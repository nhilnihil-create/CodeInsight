#include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
#include <numeric>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll gcd(ll x, ll y)
{
	if (y == 0)
		return (x);
	return (gcd(y, x % y));
}

signed main(void)
{
	ll n, mx;
	bool is_pair, is_setwise;
	cin >> n;
	vector<ll> a(n);
	mx = 0;
	rep(i, n) 
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	vector<bool> f(mx + 1, false); 
	is_pair = true;
	rep(i, n)
	{
		ll x = a[i];
		for(ll j = 2; j * j <= x; j++)
		{
			ll cnt = 0;
			while (x % j == 0)
			{
				x /= j;
				cnt++;
			}
			if (cnt > 0)
			{
				if (f[j] == true)
					is_pair = false;
				f[j] = true;
			}
		}
		if (x != 1 && f[x] == true)
			is_pair = false;
		f[x] = true;
	}
	if (is_pair)
	{
		cout << "pairwise coprime" << endl;
		return 0;
	}
	is_setwise = true;
	ll g = a[0]; 
	for(int i = 1; i < n; i++)
		g = gcd(a[i], g);
	if (g != 1)
		is_setwise = false;
	if (is_setwise)	
	{
		cout << "setwise coprime" << endl;
		return 0;
	}
	cout << "not coprime" << endl;
	return 0;
}
