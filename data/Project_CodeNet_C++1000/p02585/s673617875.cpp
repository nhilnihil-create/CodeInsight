#include <stdio.h>
long long n, k, s, x, z, y, m, b, l;
long long p[5000];
long long c[5000];
int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", p + i);
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", c + i);
	}
	m = -1000000000;
	for (int i = 0; i < n; i++) {
		s = i;
		x = 0;
		b = 0;
		while (p[s] != i) {
			s = p[s];
			x += c[s];
			b++;
		}
		x += c[i];
		b++;
		if (k > b) {
			l = b + k % b;
			y = 0;
			if (k > l) {
				if (x > 0)y += (k - l) / b * x;
			}
			s = i;
			for (int j = 0; j < l; j++) {
				s = p[s];
				y += c[s];
				if (y > m)m = y;
			}
		}
		else {
			s = i;
			y = 0;
			for (int j = 0; j < k; j++) {
				s = p[s];
				y += c[s];
				if (y > m)m = y;
			}
		}
	}
	printf("%lld\n", m);
}
