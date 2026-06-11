#include <stdio.h>
#include <math.h>

unsigned int s[100000000 / 8 + 1];

int bget(int n) {
	return (s[n / 32] >> (n % 32)) & 1;
}

int bset(int n) {
	s[n / 32] |= 1 << (n % 32);
}

void sieve(int n) {
	int m = sqrt(n);
	bset(0);
	bset(1);
	for (int k = 2; k <= m; k ++) {
		if (bget(k)) continue;
		for (int i = 2 * k; i <= n; i += k) {
			bset(i);
		}
	}
}

int main(void) {
	int n;
	sieve(100000000);
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < n; i ++) {
		int x;
		scanf("%d", &x);
		if (!bget(x)) count ++;
	}
	printf("%d\n", count);
	return 0;
}