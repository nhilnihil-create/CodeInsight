#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <stdio.h>

int main(){
	
	double r, s, l;


	scanf("%lf", &r);

	l = 2 * M_PI * r;
	s = M_PI * r * r;

	printf("%.6lf %.6lf\n", s, l);

	return 0;
}