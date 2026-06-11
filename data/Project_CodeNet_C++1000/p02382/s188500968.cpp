#include <cstdio>
#include <cmath>
int main() {
	double n, x[100], t, p, s[4] = { 0 };
	scanf("%lf", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &x[i]);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &t);
		p = std::abs(x[i] - t);
		if (s[3] < p) s[3] = p;
		for (int j = 0; j < 3; j++)
			s[j] += pow(p, j + 1);
	}
	for (int i = 0; i < 3; i++)
		printf("%f\n", pow(s[i], 1.0 / (i + 1)));
	printf("%f\n", s[3]);
}