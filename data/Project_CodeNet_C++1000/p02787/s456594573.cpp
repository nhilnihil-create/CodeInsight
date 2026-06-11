#pragma GCC optimize ("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define FORD(i, a, b) for (int i=(a); i>(b); i--)
#define PPC(x) __builtin_popcountll(x)
#define MSB(x) (31 - __builtin_clz(x))
#define SZ(x) ((int)(x).size())
#define BACK(x) prev((x).end())
#define HASK(x, y) ((x).find(y) != (x).end())
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define ithBit(m, i) ((m) >> (i) & 1)
#define ft first
#define sd second
#define kw(a) ((a) * (a))
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
 
const int maxN = 20003, INF = 1000000000;

int dp[maxN];

void solve()
{
	int h, n;
	scanf ("%d%d", &h, &n);
	fill(dp+1, dp+maxN, INF);
	while (n--)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		FOR(i, a, maxN)
			dp[i] = min(dp[i], dp[i-a] + b);
	}
	
	int res = INF;
	FOR(i, h, maxN)
		res = min(res, dp[i]);
	printf("%d\n", res);
}
 
int main()
{
	int t = 1;
	//scanf ("%d", &t);
	FOR(tid, 1, t+1)
	{
		//printf("Case #%d: ", tid);
		solve();
	}
	return 0;
}



