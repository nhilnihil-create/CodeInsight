#include<iostream>
#include<iomanip>
double r;
double pi=3.141592653589;
int main(){
	std::cin>>r;
	std::cout<<std::fixed<<std::setprecision(6)<<r*r*pi<<" "<<r*2*pi<<std::endl;
	return 0;
}