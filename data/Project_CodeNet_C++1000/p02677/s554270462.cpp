#include<iostream>
#include<cmath>
#include <iomanip>
int main(){
    int A,B,H,M;
    int hourAng,minAng;
    std::cin>>A>>B>>H>>M;
    hourAng=30*H;
    minAng=6*M;
    const double pi = 3.141592653589793;
    double hourAngRad,minAngRad;
    double hourX,hourY,minX,minY;
    minAngRad=minAng*pi/180.0;
    hourAngRad=hourAng*pi/180.0+minAngRad/12.0;
    hourX=A*cos(hourAngRad);
    hourY=A*sin(hourAngRad);
    minX=B*cos(minAngRad);
    minY=B*sin(minAngRad);
    double dx,dy;
    dx=hourX-minX;
    dy=hourY-minY;
    // std::cout<<hourAng<<","<<minAng<<std::endl;
    // std::cout<<hourX<<","<<hourY<<":"<<minX<<","<<minY<<std::endl;
    std::cout<<std::fixed << std::setprecision(15);
    std::cout<<sqrt(dx*dx+dy*dy)<<std::endl;
}