#include<cstdio>
#include<cmath>
int main() {
	int n, x[100], y, i;
	double d1 = 0, d2 = 0, d3 = 0, dinf = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &y);
		y = x[i] > y ? x[i] - y : y - x[i];
		d1 += y;
		d2 += y*y;
		d3 += y*y*y;
		dinf = dinf < y ? y : dinf;
	}
	printf("%f\n%f\n%f\n%f\n", (double)d1, std::sqrt(d2), std::cbrt(d3), (double)dinf);
	return 0;
}
