#pragma GCC optimize ("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define FORD(i, a, b) for (int i=(a); i>(b); i--)
#define PPC(x) __builtin_popcount(x)
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
 
const int maxN = 1 << 17;

int cost[maxN], dp[maxN][120];

int solve(string& T)
{
	for (char c : "rsp")
		dp[0][c] = 0;	
	int n = SZ(T);
	
	FOR(i, 1, n+1)
	{
		dp[i]['r'] = (T[i] == 's') * cost['r'] + max(dp[i-1]['s'], dp[i-1]['p']);
		dp[i]['s'] = (T[i] == 'p') * cost['s'] + max(dp[i-1]['r'], dp[i-1]['p']);
		dp[i]['p'] = (T[i] == 'r') * cost['p'] + max(dp[i-1]['s'], dp[i-1]['r']);
	}
	
	return max({dp[n]['r'], dp[n]['s'], dp[n]['p']});
}

char T[maxN];

void solve()
{
	int n, k;
	scanf ("%d%d%d%d%d", &n, &k, &cost['r'], &cost['s'], &cost['p']);
	
	dbg(cost['s']);
	
	scanf ("%s", T);
	int res = 0;
	FOR(s, 0, k)
	{
		string x = "#";
		for (int i=s; i<n; i+=k)
			x += T[i];
		res += solve(x);
		dbg(res);
	}
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
 


