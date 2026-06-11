#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

ll f(ll x, ll y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		return f(y, x % y);
	}
}
ll g(ll x, ll y)
{
	return (x - x % y) / y;
}

int main()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll gcd = f(c, d);
	ll p;
	p = c * d / gcd;
	ll m, n, l;
	
	m = g(b, c) - g(a-1, c);
	n = g(b, d) - g(a-1, d);
	l = g(b, p) - g(a-1, p);

	ll ans = b - a + 1 - m - n + l;
	cout << ans << "\n";
	return 0;
}