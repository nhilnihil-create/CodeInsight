#include <stdio.h>
#include <algorithm>
int n;
long long k, l, m, r, x;
long long a[200000];
long long f[200000];
int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", f + i);
	}
	std::sort(a, a + n);
	std::sort(f, f + n);
	r = a[n - 1] * f[n - 1];
	l = -1;
	while (r - l - 1) {
		m = (l + r) / 2;
		x = 0;
		for (int i = 0; i < n; i++) {
			if (m < a[i] * f[n - 1 - i]) {
				x += a[i] - m / f[n - 1 - i];
			}
		}
		if (x > k)l = m;
		else r = m;
	}
	printf("%lld\n", r);
}