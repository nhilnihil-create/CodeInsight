#include <stdio.h>
#pragma warning (disable:4996)

#define PI 3.14159265358979

int main() {
	int R;
	(void)scanf("%d", &R);
	double length = 2 * PI * (double)R;
	printf("%.16f", length);
}