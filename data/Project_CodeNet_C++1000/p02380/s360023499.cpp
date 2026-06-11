#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	double a,b,c,pi=3.1415926535897932;
	cin>>a>>b>>c;
	cout<<fixed<<setprecision(5)<<a*b*sin(c*pi/180.0)/2<<endl<<a+b+sqrt(a*a+b*b-2.0*a*b*cos(c*pi/180.0))<<endl<<b*sin(c*pi/180.0)<<endl;
	return 0;
}