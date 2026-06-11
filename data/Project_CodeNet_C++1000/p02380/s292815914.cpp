#include <stdio.h>
#include <math.h>

#define DEBUG

#ifndef DEBUG 
#define fprintf (void)
#endif 

double absval(double x);

int main(void){

	double a,b,C;
	double s,l,c,h;
	
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&C);
	
	C=C*M_PI/180;
	
	s=a*b*sin(C)/2;
	c=sqrt(a*a+b*b-2*a*b*cos(C));
	l=a+b+c;
	h=2*s/a;
	
	printf("%lf\n%lf\n%lf\n",s,l,h);
	
	return 0;
}