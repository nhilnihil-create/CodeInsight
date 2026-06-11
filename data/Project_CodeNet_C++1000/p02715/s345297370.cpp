#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin() , x.end()
ll modular_exp(ll a , ll n)
{
	if (a == 1) return a;
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res % mod;
}

void solve()
{
	ll n, k; cin >> n >> k;
	vector<ll>dp( k + 1 , 0); //it contains the count of elements
	for (ll i = 1; i <= k; ++i)
	{
		dp[i] = modular_exp( k / i , n);
	}
	for (ll i = k; i >= 1; --i)
	{
		for (ll j = (2 * i) ; j <= k ; j += i)
		{
			dp[i] -= dp[j];
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= k; ++i) ans = (ans + (i * dp[i]) % mod) % mod;
	cout << ans;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t = 1; //cin >> t;
	while (t--)
		solve();
	return 0;
}

