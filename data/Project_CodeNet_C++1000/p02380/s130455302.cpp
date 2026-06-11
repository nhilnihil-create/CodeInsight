#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
	double a,b,c,d,s,l,h,PI=3.14159265358979;
	cin>>a>>b>>c;
	c=(c*PI)/180;
	s=(0.5*a*b)*sin(c);
	d=sqrt(((a*a)+(b*b))-(2*a*b*cos(c)));
	h=(s*2)/a;
	l=a+b+d;
	printf("%.8lf\n%.8lf\n%.8lf\n",s,l,h);
	return 0;
}