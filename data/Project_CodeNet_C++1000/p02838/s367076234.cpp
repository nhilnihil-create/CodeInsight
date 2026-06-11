#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

ll powmod(ll a, ll n, ll mod) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2 == 1) { ret = ret * a % mod; }
		a = a * a % mod;
		n /= 2;
	}
	return ret;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	ll ans = 0;
	for(int i = 0; i < 60; ++i)
	{
		ll d0 = 0, d1 = 0;
		for(int j = 0; j < n; ++j)
		{
			// i 桁目が 1 か 0 か
			if((a[j] >> i) & 1) ++d1;
			else ++d0;
		}

		// i 桁目が 1 である個数
		ll n = d0 * d1 % MOD;

		// i 桁目の総和 (= 2^i * d0 * d1)
		ll tmp = powmod(2, i, MOD) * n % MOD;

		ans = (ans + tmp) % MOD;
	}
	cout << ans << endl;	
}

int main()
{
	fastio;
	solve();

	return 0;
}