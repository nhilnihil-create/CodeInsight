#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES // for C++  
#include <cmath> 
using namespace std;
int main(){
	double pi=3.1415926535;
	double r;
	cin>>r;
	
	double men,en;
	men=r*r*M_PI;
	en=2*r*M_PI;
	
	

	cout<<fixed<<setprecision(6)<<men<<' '<<en<<endl;
	
}
