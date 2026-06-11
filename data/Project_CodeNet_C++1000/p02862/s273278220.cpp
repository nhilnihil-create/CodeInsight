#include <bits/stdc++.h>

using namespace std;

const int MAX = 1010000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void combinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long comb(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {

	long long x, y;
	cin >> x >> y;

	if ((x + y) % 3 != 0) {
		cout << 0 << endl;;
	}
	else {
		long long a = min((2 * y - x) / 3, (2 * x - y) / 3);
		combinit();
		cout << comb((x + y) / 3, a) << endl;
	}



	return 0;
}