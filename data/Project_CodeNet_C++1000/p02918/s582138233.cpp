#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];
#define forr(a,b) for(ll i=a;i<b;i++);
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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll y = 0;
	ll no = 0;
	for (ll i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			y++;
		}
		else no++;
	}
	ll ans = y + min(2 * k, no);
	cout << ans << "\n";
}