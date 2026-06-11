#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 10000000;  // TLEならば小さくする
const ll MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {

	ll x, y; cin >> x >> y;	
	if (y > 2 * x || y < x / 2 || (x + y) % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	ll num = (x + y) / 3;
	ll num_x = (2 * x - y) / 3;
	ll num_y = (-x + 2 * y) / 3;
		
	if (num_x < 0 || num_y < 0) {
		cout << 0 << endl;
		return 0;
	}

	COMinit(); // 前処理
	cout << COM(num, num_y) << endl;	
	return 0;
}