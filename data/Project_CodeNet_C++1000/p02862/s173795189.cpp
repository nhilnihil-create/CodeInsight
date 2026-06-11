#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 1000005;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void com_init() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll com(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	int x, y;
	cin >> x >> y;
	com_init();
	int ans = 0;
	if ((x + y) % 3 == 0) {
		int n = (2 * y - x) / 3;
		int m = (2 * x - y) / 3;
		if (n >= 0 && m >= 0) ans = com(n + m, n);
	}
	cout << ans << endl;
	return 0;
}