#include <cmath>
#include <cstdio>
int n, s, p[1000]; double d;
int main() {
	while(~scanf("%d", &n)) {
		if(n == 0) break; d = 0, s = 0;
		for(int i = 0; i < n; i++) scanf("%d", &p[i]), s += p[i];
		for(int i = 0; i < n; i++) {
			d += (p[i] - 1.0 * s / n) * (p[i] - 1.0 * s / n);
		}
		printf("%.9f\n", sqrt(d / n));
	}
	return 0;
}