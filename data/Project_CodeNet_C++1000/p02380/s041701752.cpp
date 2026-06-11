#include<stdio.h>
#include<math.h>

int main(){
	
	double a,b,x,S,L,h;
	
	scanf("%lf %lf %lf",&a,&b,&x);
	
	S=0.5*a*b*sin(x*M_PI/180);
	L=a+b+sqrt(a*a+b*b-2*a*b*cos(x*M_PI/180));
	h=b*sin(x*M_PI/180);
	
	printf("%lf\n%lf\n%lf\n",S,L,h);
	
	return 0;
}