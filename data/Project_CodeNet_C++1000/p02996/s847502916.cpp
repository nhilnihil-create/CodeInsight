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


void solve(int tc)
{
	int n;
	cin >> n;

	ll time = 0;

	pair<int, int> a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	sort(a, a + n, [](auto& a, auto& b)
	{
		return a.S < b.S;
	});

	for (int i = 0; i < n; i++)
	{
		time += a[i].F;
		if (time > a[i].S)
			return void(cout << "No\n");
	}
	cout << "Yes\n";
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
