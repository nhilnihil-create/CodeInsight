#include<cstdio>
#include<cmath>

int main()
{
	double a,b,c;
	double PI = acos(-1.0);
	double S,L,H;
	scanf("%lf %lf %lf",&a,&b,&c);
    S=a*b*sin(c/180*PI)/2;
	L=sqrt(a*a+b*b-2*a*b*cos(c/180*PI))+a+b;
	H=2*S/a;
	printf("%.6lf\n%.6lf\n%.6lf\n",S,L,H);
	return 0;
}