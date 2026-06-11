#include<stdio.h>
#include<math.h>
int main(void)
{
	double r,f,x,y;
	f=M_PI;
	scanf("%lf",&r);
	x=r*r*f;
	y=2.0*f*r;
	printf("%lf %lf\n",x,y);
	return 0;
}

