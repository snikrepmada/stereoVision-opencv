#include <opencv2/opencv.hpp>

int main()
{
    //initialize and allocate memory to load the video stream from camera
    cv::VideoCapture camera0(0);
    cv::VideoCapture camera1(1);

    if( !camera0.isOpened() ) return 1;
    if( !camera1.isOpened() ) return 1;

    while(true) {
        //grab and retrieve each frames of the video sequentially
        cv::Mat3b frame0;
        camera0 >> frame0;
        cv::Mat3b frame1;
        camera1 >> frame1;

        cv::imshow("Video0", frame0);
        cv::imshow("Video1", frame1);

        //wait for 40 milliseconds
        int c = cvWaitKey(40);

        //exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
        if(27 == char(c)) break;
    }

    return 0;
}