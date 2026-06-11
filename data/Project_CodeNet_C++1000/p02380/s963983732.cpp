#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main() {
	double a,b,t;
	scanf("%lf%lf%lf",&a,&b,&t);
	
	double s=0.5*a*b*sin(t/180.0*PI);
	double c=sqrt(a*a+b*b-2*a*b*cos(t/180.0*PI));
	double l=a+b+c;
	double h=s*2/a;
	
	printf("%lf %lf %lf\n",s,l,h);
	return 0;
}