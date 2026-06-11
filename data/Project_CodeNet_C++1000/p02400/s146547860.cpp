#include<stdio.h>
main(){
	double r;
	double S,D;
	double pi = 3.141592653589;

	scanf("%lf",&r);
	S = r * r * pi;
	D = 2 * r * pi;

	printf("%f %f\n",S,D);
	
	return 0;
}