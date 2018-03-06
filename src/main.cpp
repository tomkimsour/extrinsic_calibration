#include "calibrator.hpp"

#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "extrinsic_calibration_node");

  Calibrator calib;

  cv::namedWindow("image_rgb", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("image_ir", cv::WINDOW_AUTOSIZE);
  cv::waitKey(1);

  ros::Rate rate(10);

  std::cout << std::endl << "Please, ensure that you see an image "
            << "in -image_rgb- window and press a key "
            << "to choose an operating mode:"
            << std::endl
            << "* press -s- key to save an image pair: "
            << "place your calibration pattern in front of the robot "
            << "and save an image pair when the pattern is detected; "
            << "you should save it at different positions, orientations, scales "
            << "(at least 20 pairs or more)"
            << std::endl
            << "* press -c- key to process the recorded data"
            << std::endl;

  uchar key_pressed;
  while(ros::ok())
  {
    //std::cout << "1" << std::endl;
    ros::spinOnce();

    //std::cout << "2" << std::endl;
    if ((key_pressed = cv::waitKey(10)) != -1)
    {
      //std::cout << "3" << std::endl;
      /*if (key_pressed == 'r')
      {
        calib.saveImagePairs();
      }
      else*/ if (key_pressed == 's')
      {
       //std::cout << "4" << std::endl;
        calib.saveImagePair();
      }
      else if (key_pressed == 'c')
      {
        //std::cout << "5" << std::endl;
        calib.readAndProcessImages();
        ros::shutdown();
      }
      //std::cout << "6" << std::endl;
    }
    //std::cout << "7" << std::endl;
    rate.sleep();
  }

  //std::cout << "8" << std::endl;
  ros::shutdown();
  return 0;
}
