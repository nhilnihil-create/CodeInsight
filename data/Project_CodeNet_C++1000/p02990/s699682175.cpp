#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//詳細:https://drken1215.hatenablog.com/entry/2018/06/08/210000
const int MAX = 5100000;
const int MOD = 1000000007;
vector<ll>fac(MAX);
vector<ll>finv(MAX);
vector<ll>inv(MAX);
// テーブルを作る前処理
void COMinit() {
	fac.at(0) = 1;
	fac.at(1) = 1;
	finv.at(0) = 1;
	finv.at(1) = 1;
	inv.at(1) = 1;
	for (int i = 2; i < MAX; i++) {
		fac.at(i) = fac.at(i - 1) * i % MOD;
		inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
		finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
	}
}
// 二項係数計算
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac.at(n) * (finv.at(k) * finv.at(n - k) % MOD) % MOD;
}

int main() {
	COMinit();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		ll ans = COM(k - 1, i - 1) * COM(n - k + 1, i);
		ans %= MOD;
		cout << ans << endl;
	}
}