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

using ll = long long;
ll M = 10010;
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
	return a / gcd(a, b) * b;
}
using namespace std;
int main()
{
	ll a, b;
	int c, d;
	cin >> a >> b >> c >> d;
	ll zg = max(a, b);
	ll zk = min(a, b);
	ll kb = lcm(c, d);
	ll c1 = zg / c;
	ll c2 = (zk - 1) / c;
	ll d1 = zg / d;
	ll d2 = (zk - 1) / d;
	ll k1 = zg / kb;
	ll k2 = (zk - 1) / kb;
	cout << b - a + 1 - (c1 + d1 - k1) + (c2 + d2 - k2);
}

