#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;

ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}


int main()
{
	ll a, b;
	ll c, d;
	cin >> a >> b >> c >> d;
	ll ans = b - a + 1;
	ll bc = b / c;
	ll bd = b / d;
	ll ac = (a-1) / c;
	ll ad = (a-1) / d;
	ll t = lcm(c, d);
	ll bt = b / t;
	ll at = (a - 1) / t;
	ans -= (bc + bd);
	ans += bt;
	ans += (ac + ad);
	ans -= at;
	cout << ans;
}