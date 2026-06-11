#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<unordered_map>
#include<iomanip>
#include<queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
ll amari = 1000000007;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];
#define forr(a,b) for(ll i=a;i<b;i++);
ll modpow(ll a, ll n, ll mod)
{
	ll res = 1;
	while (0 < n)
	{
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
ll gcd(ll x, ll y)
{
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}
// 1or素数だと１を返す
ll prime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}



int main()
{
	ll n;
	cin >> n;
	ll k = n;
	ll x = sqrt(n);
	vector<ll> a(x+10, 0);

	for (ll i = 2; i < x + 5; i++)
	{
		while (k % i == 0)
		{
			a[i]++;
			k /= i;
		}
	}


	ll ans = 0;
	ll y = 0;
	for (ll i = 0; i < x+5; i++)
	{
		if (a[i] != 0)
		{
			y = 0;
			while (y * (y + 1) <= 2 * a[i])
			{
				y++;
			}
			y--;
			ans += y;
		}
	}
	if(k!=1) ans++;
	cout << ans << "\n";
  
	return 0;
}