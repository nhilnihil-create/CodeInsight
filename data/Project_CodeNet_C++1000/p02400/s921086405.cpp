#include<stdio.h>
int main(){
	double pi=3.141592653589793238;
	double r;
	scanf("%lf", &r);
	printf("%.6lf %.6lf\n", pi*r*r, 2*pi*r);
}
