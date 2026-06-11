#include<stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	double r,pi,a,b;
	scanf("%lf",&r);
	pi=M_PI;
	a=r*r*pi;
	b=2*r*pi;
	
	printf("%lf %lf",a,b);

	return 0;
}