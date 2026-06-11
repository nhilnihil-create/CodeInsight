#include<iostream>
#include<iomanip>
int a,b;
int main(){
	std::cin>>a>>b;
	std::cout<<a/b<<" "<<a%b<<" "<<std::fixed<<std::setprecision(8)<<static_cast<double>(a)/static_cast<double>(b)<<std::endl;
	return 0;
}