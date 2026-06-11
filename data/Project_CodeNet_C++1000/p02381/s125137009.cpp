#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI (3.1415926535898)

int main(void) {

	int n;
	int s[1000];
	double total;
	for(;;) {
		total = 0;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		double m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
			m = m + s[i];
		}
		double ave = m / n;

		for (int i = 0; i < n; i++) {
			double tmp =  (s[i] - ave) * (s[i] - ave);
			total += tmp;
		}

		double hensa = sqrt(total / (double)n);
		printf("%lf\n", hensa);

	}

}