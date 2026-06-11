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

// 重複組み合わせ計算
// n 種類のものから重複を許して r 個選ぶ場合の数
// r 個のものを n グループに(0個を許して)割り当てる場合の数
// n - 1 個の仕切りと r 個の玉を一列に並べる場合の数
long long H(long long n, long long r) {
	return COM(n + r - 1, r);
}

int main() {
	
	ll n, k; cin >> n >> k;
	ll red = n - k;
	COMinit(); // 前処理
	for (ll i = 1; i <= k; i++) {
		ll x = H(i, k - i);
		ll y = H(i + 1, red - (i - 1));
		ll ans = x * y;
		ans %= MOD;
		cout << ans << endl;
	}
	return 0;
}