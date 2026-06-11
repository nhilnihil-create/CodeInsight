#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];

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
	ll a, b;
	cin >> a >> b;
	ll ans = 1;

	ll c = gcd(a, b);

	for (ll i = 2; i*i <= c; i++)
	{
		if (c % i == 0 )
		{
			ans++;
			while (c % i == 0)
			{
				c /= i;
			}
		}
	}
	if (1 < c) ans++;
	cout << ans << "\n";

	return 0;
}