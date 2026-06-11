#include<stdio.h>
#include<math.h>

int main(void)
{
	int a,b,c;
	double s=0,l=0,h=0,ra,pi=3.141592653589;
	scanf("%d%d%d",&a,&b,&c);
	ra=c*pi/180;
	s=0.5*a*b*sin(ra);
	l=sqrt(a*a+b*b-2*a*b*cos(ra))+a+b;
	h=s*2/a;
	printf("%8lf\n%8lf\n%8lf\n",s,l,h);
    return 0;
}