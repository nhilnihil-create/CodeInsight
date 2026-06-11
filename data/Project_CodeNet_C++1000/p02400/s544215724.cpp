#include <stdio.h>

int main (void)
{
	double syu,men,pai;
	double r;

	scanf("%lf",&r);

	pai = 3.141592653589;

	men = r*r*pai;
	syu = 2*r*pai;

	printf("%f %f\n",men,syu);

	return 0;
}