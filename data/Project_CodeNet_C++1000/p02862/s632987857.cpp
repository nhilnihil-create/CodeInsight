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
	ll x, y;
	cin >> x >> y;
	ll ans, p, q;
	if ((2 * x - y) % 3 != 0||2*y<x||2*x<y)
	{
		ans = 0;
	}
	else
	{
    
		p = (2 * y - x) / 3;
		q = (2 * x - y) / 3;
      
		ll r;
		r = p + q;
		vector<ll> fact(r + 100);
        vector<ll> inv(r + 100);
        vector<ll> factinv(r + 100);
		fact[1] = 1;
        fact[0]=1;
		inv[1] = 1;
		factinv[1] = 1; 
      	factinv[0]=1;
		for (ll i = 2; i < r + 10; i++)
		{
			fact[i] = (fact[i - 1] * i) % amari;
			inv[i] = (amari - (inv[amari % i] * (amari / i))%amari) % amari;
			factinv[i] = (factinv[i - 1] * inv[i]) % amari;
		}

		ans = amari*10+(fact[p + q] * factinv[p] % amari) * factinv[q];
       ans%=amari;
	}

	cout <<ans << "\n";

	return 0;
}