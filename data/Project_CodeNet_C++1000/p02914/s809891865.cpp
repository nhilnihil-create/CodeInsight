#include <stdio.h>
int n, x, y, z;
long long a[100000];
long long s, t, u, v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		s ^= a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[i] & (~s);
	}
	for (int i = 0; i < 60; i++) {
		t = 1;
		t <<= (59 - i);
		z = 0;
		for (int j = x; j < n; j++) {
			if (a[j] & t) {
				y = j;
				z = 1;
				break;
			}
		}
		if (z) {
			u = a[y];
			a[y] = a[x];
			a[x] = u;
			for (int j = 0; j < n; j++) {
				if ((a[j] & t) && (j - x))a[j] ^= a[x];
			}
			x++;
		}
	}
	for (int i = 0; i < x; i++) {
		t = 1;
		t <<= 59;
		while (t > a[i])t /= 2;
		if (!(v & t))v ^= a[i];
	}
	printf("%lld\n", s + v * 2);
}