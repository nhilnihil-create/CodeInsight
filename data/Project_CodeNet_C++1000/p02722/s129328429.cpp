#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0)
//#define MULTI_TEST
//#define GOOGLE
#ifdef LOCAL
#include "debugger.h"
#else
#define db(...)
#endif
#define ll long long
#define v32 vector<int>
#define v64 vector<ll>
#define s32 set<int>
#define s64 set<ll>
#define p32 pair<int, int>
#define p64 pair<ll, ll>
#define sz(v) (ll)(v).size()
#define fi first
#define se second
#define ln '\n'
const ll MOD = 1e9 + 7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

void solve()
{
	ll n;
	cin >> n;
	if (n == 2)
	{
		cout << 1 << ln;
		return;
	}
	// for (int x = 2; x <= n; x++)
	// {
	// 	int temp = n;
	// 	while (temp >= x)
	// 	{
	// 		if (temp % x == 0)
	// 			temp /= x;
	// 		else
	// 			temp -= x;
	// 	}
	// 	if (temp == 1)
	// 		cout << x << " ";
	// }
	// cout << "lol\n";
	s64 ans;
	ans.insert(n);
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ll temp = n;
			while (temp % i == 0)
			{
				temp /= i;
			}
			if (temp % i == 1)
				ans.insert(i);
			temp = n;
			ll j = n / i;
			while (temp % j == 0)
				temp /= j;
			if (temp % j == 1)
				ans.insert(j);
		}
	}
	ans.insert(n - 1);
	for (ll i = 2; i * i <= (n - 1); i++)
	{
		if ((n - 1) % i == 0)
		{
			ans.insert(i);
			ans.insert((n - 1) / i);
		}
	}
	cout << sz(ans) << ln;
	return;
}

int main()
{
#ifndef LOCAL
	FASTIO;
#endif
	int t = 1;
#ifdef LOCAL
	clock_t start, stop;
	start = clock();
#endif
#ifdef MULTI_TEST
	cin >> t;
#endif
	for (int tc = 1; tc < t + 1; tc++)
	{
#ifdef GOOGLE
		cout << "Case #" << tc << ": ";
#endif
		solve();
	}
#ifdef LOCAL
	stop = clock();
	cerr << "Time :" << fixed << setprecision(5) << double(stop - start) / double(CLOCKS_PER_SEC) << "s" << ln;
#endif
	return 0;
}
