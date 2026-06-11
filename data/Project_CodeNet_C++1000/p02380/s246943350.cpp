#include <stdio.h>
#include <math.h>
#include <string.h>
#define rep(i,a,n) for(int i=a;i<n;i++)

int main(){
	double a,b,C,S,L,h,PI=acos(-1.0);
	scanf("%lf %lf %lf",&a,&b,&C);
	S=0.5*a*b*sin(C*PI/180.0);
	L=a+b+sqrt(a*a+b*b-2*a*b*cos(C*PI/180.0));
	h=b*sin(C*PI/180.0);
	printf("%.10lf\n%.10lf\n%.10lf\n",S,L,h);
	return 0;
}