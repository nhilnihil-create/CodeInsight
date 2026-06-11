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

const int N = 2005;
ll dp[N][N];

ll go(int i, int j, int n, vector<p64> &arr)
{
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int idx = n - (j - i + 1) + 1;
	ll ans = arr[idx].fi * abs(arr[idx].se - i) + go(i + 1, j, n, arr);
	ans = max(ans, arr[idx].fi * abs(j - arr[idx].se) + go(i, j - 1, n, arr));
	return dp[i][j] = ans;
}

void solve()
{
	int n;
	cin >> n;
	vector<p64> arr(n + 1);
	for (int i = 1; i < n + 1; i++)
		cin >> arr[i].fi, arr[i].se = i;
	sort(arr.begin(), arr.end());
	reverse(arr.begin() + 1, arr.end());
	db(arr);
	memset(dp, -1, sizeof(dp));
	cout << go(1, n, n, arr) << ln;
	return;
}

int main()
{
	FASTIO;
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
