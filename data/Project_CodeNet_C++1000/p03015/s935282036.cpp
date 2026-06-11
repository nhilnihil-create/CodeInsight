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

const int N = 1e5 + 5;
ll dp[N][2];
ll go(int i, int j, int n, string &l)
{
	if (i == n)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	ll ans = 0;
	if (j == 1)
	{
		if (l[i] == '1')
		{
			ans = add(ans, mul(2ll, go(i + 1, 1, n, l), MOD), MOD);
			ans = add(ans, go(i + 1, 0, n, l), MOD);
		}
		else
			ans = add(ans, go(i + 1, 1, n, l), MOD);
	}
	else
		ans = add(ans, mul(3ll, go(i + 1, 0, n, l), MOD), MOD);
	return dp[i][j] = ans;
}
void solve(int tc)
{
	string l;
	cin >> l;
	int n = l.length();
	memset(dp, -1, sizeof(dp));
	ll ans = go(0, 1, n, l);
	cout << ans << ln;
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
		solve(tc);
	}
#ifdef LOCAL
	stop = clock();
	cerr << "Time :" << fixed << setprecision(5) << double(stop - start) / double(CLOCKS_PER_SEC) << "s" << ln;
#endif
	return 0;
}
