#include <cstdio>
#include <cmath>
int main() {
	double n, m, a, p[1000];
	while (scanf("%lf", &n), n != 0) {
		m = 0;
		a = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &p[i]);
			m += p[i];
		}
		m /= n;
		for (int i = 0; i < n; i++)
			a += pow(p[i] - m, 2);
		printf("%f\n", sqrt(a / n));
	}
}