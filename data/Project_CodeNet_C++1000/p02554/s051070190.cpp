#include <iostream>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

constexpr ll MOD = 1000000007;

ll powmod(ll a, ll p)
{
	a %= MOD;

	ll result = 1;
	while(p) 
	{
		if(p&1)
			result = (result * a) % MOD;

		a = (a * a) % MOD;
		p >>= 1;
	}
	return result;
}

void solve()
{
	ll n; cin >> n;

	ll total = powmod(10, n);
	ll r = powmod(8, n);
	ll pr = powmod(9, n);

	ll ans = total - pr - pr + r;
	ans %= MOD;
	ans = (ans + MOD) % MOD;
	cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}