#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(){
	double a,b,c,s,l,h;
	cin >> a >> b >> c;
	s=0.5*a*b*sin((M_PI*c*1.0)/180);
	l=a+b+sqrt(pow(a,2.0)+pow(b,2.0)-2*a*b*cos((M_PI*c*1.0)/180));
	h=b*sin((M_PI*c*1.0)/180);
	printf("%.8f\n%.8f\n%.8f\n",s,l,h);
}