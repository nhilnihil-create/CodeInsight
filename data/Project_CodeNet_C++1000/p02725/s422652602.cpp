#include<bits/stdc++.h>
using namespace std;
#define ll         long long
#define mod        1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf        1e18
#define ps(x,y)    fixed<<setprecision(y)<<x

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll k, n;
	cin >> k >> n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll ans = LLONG_MIN;
	for (int i = 0; i < n; ++i)
	{	if (i == n - 1)
			ans = max(k - a[i] + a[0], ans);
		else
			ans = max(a[i + 1] - a[i], ans);
	}
	cout << k - ans;

}