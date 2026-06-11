#include <stdio.h>

int main(void){
	double r, p, are, circ ;
	scanf("%lf", &r);
	p = 3.141592653589;
	are = 1.0*r*r*p ;
	circ = 2*r*p ;
	printf("%f %f\n", are, circ);
	
    return 0;
}