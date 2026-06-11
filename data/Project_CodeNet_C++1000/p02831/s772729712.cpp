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
	int a, b;
	cin >> a >> b;
	ll t = max(a, b);
	ll m = min(a, b);
	ll ans = lcm(t, m);
	cout << ans;
}
