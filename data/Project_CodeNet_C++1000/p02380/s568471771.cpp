#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main(){
	long double a,b,c;
	long double x;  //??????????????????
	long double s,l,h;
	
	cin>>a>>b>>c;
	
	s=a*b*sin(c*M_PI/180.0)/2;
	x=sqrt(a*a+b*b-2*a*b*cos(c*M_PI/180.0));
	l=a+b+x;
	h=2*s/a;
	
	cout<<fixed<<setprecision(9)<<s<<endl;
	cout<<fixed<<setprecision(9)<<l<<endl;
	cout<<fixed<<setprecision(9)<<h<<endl;
}