#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MAX = 10000000;  // TLEならば小さくする
const long long MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (long long i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(long long n, long long k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	
	ll s; cin >> s;
	COMinit(); // 前処理
	ll n = s / 3;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll x = s - 3 * i;
		ans += COM(i + x - 1, x);
		ans %= MOD;
	}
	cout << ans << endl;	
    return 0;
}