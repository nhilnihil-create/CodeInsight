#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 510000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k)
{
	if (n < k)
		return 0;
	if (n < 0 || k < 0)
		return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	ll n,k;
	cin >> n >> k;

	COMinit();

	ll ans = 0;
	for(ll i=k; i<=n+1; i++){
		ll max = (n-i+1+n)*i/2;
		ll min = (0+i-1)*i/2;
		ans += max-min+1;
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}