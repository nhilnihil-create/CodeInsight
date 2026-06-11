#include <stdio.h>
#include <math.h>

int main(){
	double r;
	double PI=acos(-1.0);
	scanf("%lf",&r);
	printf("%.10lf %.10lf\n",PI*r*r,2*PI*r);
	return 0;
}