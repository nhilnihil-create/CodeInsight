#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

long long MOD = 1000000000 + 7;

long long modPow(int n, int num) {
	if (num == 0) return 1;
	long long res = modPow(n, num / 2);
	if (num % 2 == 0) res = (res * res) % MOD;
	else res = (((res * res) % MOD) * n) % MOD;
	return res;
}

long long modNck(int n, int k) {
	long long res = 1;
	for (int i = 0; i < k; i++) {
		res = (res * ((long long)n - i) % MOD * modPow(i + 1, MOD - 2)) % MOD;
	}
	return res;
}

int main() {
	long long X, Y;
	cin >> X >> Y;

	long long a, b;
	if ((2 * Y - X) % 3 == 0) {
		a = (2 * Y - X) / 3;
	}
	else {
		cout << 0;
		return 0;
	}
	b = Y - 2 * a;
	if (a < 0 || b < 0) {
		cout << 0;
		return 0;
	}

	long long ans = modNck(a + b, min(a, b)) % MOD;
	cout << ans;
}