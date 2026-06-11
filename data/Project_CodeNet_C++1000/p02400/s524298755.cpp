#include <stdio.h>
#define PI 3.141592653589

int main(){
	double r;
	double area, perim;
	
	scanf("%lf", &r);
	area = r*r*PI;
	perim = 2*r*PI;

	printf("%f %f\n", area, perim);
	return 0;
}