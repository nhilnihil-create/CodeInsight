#include <stdio.h>
long long k, q, s;
long long n, x, m, t, f, g;
long long d[5000];
long long e[5000];
int main() {
	scanf("%lld%lld", &k, &q);
	for (long long i = 0; i < k; i++) {
		scanf("%lld", d + i);
	}
	for (long long i = 0; i < q; i++) {
		scanf("%lld%lld%lld", &n, &x, &m);
		s = 0;
		f = 0; g = 0;
		for (long long j = 0; j < k; j++) {
			e[j] = d[j] % m;
			s += e[j];
			if (e[j] == 0)g++;
		}
		n -= 2;
		t = x;
		t += (n / k) * s;
		f += (n / k) * g;
		for (long long j = 0; j <= n % k; j++) {
			t += e[j];
			if (e[j] == 0)f++;
		}
		printf("%lld\n", (n + 1) - t / m + x / m - f);
	}
}