#include <cstdio>
#include <cmath>

int main(){
	double a, b, C;
	scanf("%lf %lf %lf", &a,&b,&C);
	printf("%.8lf\n", 0.5*a*b*sin(M_PI*C/180));
	printf("%.8lf\n", sqrt(a*a+b*b-2*a*b*cos(M_PI*C/180))+a+b);
	printf("%.8lf\n", b*sin(M_PI*C/180));	
}
