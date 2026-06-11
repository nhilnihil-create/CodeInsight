#include<cstdio>
#include<cmath>
int main() {
	int n, i;
	double s, a2, a;
	while (true) {
		scanf("%d", &n);
		if (n == 0)break;
		a = 0;
		a2 = 0;
		for (i = 0; i < n; i++) {
			scanf("%lf", &s);
			a += s;
			a2 += s*s;
		}
		printf("%f\n", std::sqrt(a2/n - a/n*a/n));
	}
	return 0;
}
