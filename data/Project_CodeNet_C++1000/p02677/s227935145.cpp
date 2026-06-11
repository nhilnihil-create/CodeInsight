#include<cstdio>
#include<cmath>
const double PI=acos(-1);
double min(double a,double b)
{
	return a<b?a:b;
}
int main(void)
{
	double a,b,h,m;
	scanf("%lf%lf%lf%lf",&a,&b,&h,&m);
	double r1,r2,R;
	r1=h*PI/6.0+PI*m/360.0;
	r2=m*PI/30.0;
	r1=fabs(r1-r2);
	R=min(r1,2.0*PI-r1);
	printf("%.20lf\n",sqrt(fabs(a*a+b*b-2.0*a*b*cos(R))));
	return 0;
 } 
// min(fabs(h*360.0/12.0-m*360.0/60.0),fabs(360.0-fabs(h*360.0/12-m*360.0/60.0)))