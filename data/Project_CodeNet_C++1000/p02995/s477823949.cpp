#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 5

// for using in pairs
#define F first
#define S second

// aliases
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;

ll gcd(ll a, ll b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}

void solve(int tc)
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll L = lcm(c, d);

	a--;

	ll A = b - b / c - b / d + b / L;
	ll B = a - a / c - a / d + a / L;

	cout << A - B << "\n"; 

}

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
	return 0;
}
