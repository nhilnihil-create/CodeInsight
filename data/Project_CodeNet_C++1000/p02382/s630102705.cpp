#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI (3.1415926535898)

int main(void) {

	int n;

	double x[100];
	double y[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lf", &x[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%lf", &y[i]);
	}

	double total1 = 0.0;
	double total2 = 0.0;
	double total3 = 0.0;
	double total4 = 0.0;
	for (int i = 0; i < n; i++) {
		double tmp = fabs(y[i] - x[i]);
		total1 += tmp;
		total2 += (tmp * tmp);
		total3 += (tmp * tmp * tmp);
		if (total4 < tmp) {
			total4 = tmp;
		}
	}
	total2 = sqrt(total2);
	total3 = cbrt(total3);

	printf("%lf\n", total1);
	printf("%lf\n", total2);
	printf("%lf\n", total3);
	printf("%lf\n", total4);


}