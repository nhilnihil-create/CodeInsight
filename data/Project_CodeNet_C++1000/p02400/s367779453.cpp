#include<iostream>
#include<math.h>
#include<iomanip>
int main(){
	double r;
	std::cin>>r;
	double s = M_PI*r*r;
	double l = M_PI*2.0*r;
	std::cout.setf(std::ios::showpoint);
	std::cout<<std::fixed<<std::setprecision(6)<<s<<' '<<l<<std::endl;
}