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
 
const int maxN = 1 << 19;

long long T[20][20];

void solve()
{
	int n;
	scanf ("%d", &n);
	FOR(i, 1, n+1) if (i % 10 != 0)
	{
		int a = i % 10, b = i;
		while (b >= 10)
			b /= 10;
		T[a][b]++;
	}
	
	long long res = 0;
	FOR(i, 1, 10) FOR(j, 1, 10)
		res += T[i][j] * T[j][i];
	printf("%lld\n", res);
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



