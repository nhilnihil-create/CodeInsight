#include<stdio.h>
#include<math.h>
int main(void)
{
	double s,d,f,g,h,j,i,k,a,b,C,za;
	scanf("%lf %lf %lf",&a,&b,&C);
	//printf("%lf %lf %lf",a,b,C);
	k=0.5;
	za=3.1415926535;
	C=za/180*C;
	g=k*a*b*sin(C);
	f=a+b+(sqrt((a*a+b*b)-(2*a*b*cos(C))));
	//printf("%lf %lf\n",sqrt(a*a+b*b)-2*a*b*cos(C),a+b+(sqrt((a*a+b*b)-(2*a*b*cos(C)))));
	h=b*sin(C);
	printf("%lf\n%lf\n%lf\n",g,f,h);
	return 0;
}