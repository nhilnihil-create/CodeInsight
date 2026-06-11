#pragma GCC optimize("O2")
#include <bits/stdc++.h>
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

const int N = 1e6 + 1;
int nat[N];

void solve(int tc)
{
	int n;
	cin >> n;
	unordered_map<int, int> pres;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		pres[item]++;
	}
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (pres[i])
		{
			if (nat[i] == 0 && pres[i] == 1)
				ans++;
			for (int j = 2 * i; j < N; j += i)
				nat[j]++;
		}
	}
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
