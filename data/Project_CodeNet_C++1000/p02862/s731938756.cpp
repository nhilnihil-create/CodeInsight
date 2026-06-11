#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAX = 1000000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	COMinit();
	int x, y;
	cin >> x >> y;
	int m = -1, n = -1;
	for (int a = 0; a <= x; a++) {
		if ((x - a) % 2 == 1) continue;
		int b = (x - a) / 2;
		if (a * 2 + b == y) {
			m = a;
			n = b;
			break;
		}
	}
	ll ans = COM(m + n, m);
	cout << ans << endl;
	return 0;
}