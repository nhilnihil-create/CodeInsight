#include <stdio.h>

int main(void){
	double a, b;
	
	scanf("%lf %lf", &a, &b);

	
	
	printf("%d %d %f\n", (int)a / (int)b, (int)a%(int)b, a / b);
	return 0;
}