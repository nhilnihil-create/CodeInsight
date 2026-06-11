// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000, MD = 1000000007;

int kk[N + 1];
char mobius[N + 1];

int power(long long a, int k) {
	long long p = 1;
	while (k) {
		if (k & 1)
			p = p * a % MD;
		a = a * a % MD;
		k >>= 1;
	}
	return p;
}

int main() {
	int m, n; cin >> m >> n;
	fill(mobius, mobius + n + 1, 2);
	mobius[1] = 1;
	for (int a = 2; a <= n; a++) {
		if (mobius[a] != 2)
			continue;
		for (int b = a; b <= n; b += a)
			if (mobius[b] == 2)
				mobius[b] = -1;
			else
				mobius[b] *= -1;
		if (a <= n / a) {
			int a2 = a * a;
			for (int b = a2; b <= n; b += a2)
				mobius[b] = 0;
		}
	}
	for (int a = 1, b = n; a <= n / a; a++) {
		kk[a] = power(n / a, m);
		int p = power(a, m);
		while (b > n / (a + 1))
			kk[b--] = p;
	}
	long long ans = 0;
	for (int a = 1; a <= n; a++) {
		int k = 0;
		for (int b = 1; b <= n / a; b++)
			k = (k + kk[a * b] * mobius[b]) % MD;
		ans = (ans + (long long) k * a) % MD;
	}
	if (ans < 0)
		ans += MD;
	cout << ans << '\n';
	return 0;
}
