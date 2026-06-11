#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// a^n mod を計算する
ll powmod(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0)
	{
        if (n & 1)
		{
			res = res * a % mod;
		}
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	
	vector<ll> pool(k + 1, 0);
	for(int i = k; i >= 1; --i)
	{
		pool[i] = powmod((k / i), n, MOD);
		for(int j = i * 2; j <= k; j += i)
		{
			pool[i] -= pool[j];
		}
	}


	ll ans = 0;
	for(ll i = 1; i <= k; ++i)
	{
		ans += (pool[i] * i) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}


int main()
{
	fastio;
	solve();

	return 0;
}