#include<stdio.h>
int main(){
	double r;
	double S=0.0,L=0.0,pi=3.14159265359;
	scanf("%lf",&r);
	S=r*r*pi;
	L=r*2*pi;
	printf("%.6lf %.6lf\n",S,L);
	return 0;
}