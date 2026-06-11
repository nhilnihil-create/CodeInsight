#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(int)(b); i++)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define st first
#define nd second
#define KW(a) ((a)*(a))
using namespace std;
 
const int maxN = 1 << 9;
const long long INF = 1000000000000000ll;

int T[maxN];
long long dp[maxN][maxN];

void solve()
{
	int n, k;
	scanf ("%d%d", &n, &k);
	FOR(i, 1, n+1)
		scanf ("%d", T+i);
	FOR(j, 1, k+1)
		dp[0][j] = INF;
	FOR(i, 1, n+2) FOR(j, 0, k+1)
	{
		dp[i][j] = INF;
		FOR(m, 0, min(j+1, i))
			dp[i][j] = min(dp[i][j], dp[i-m-1][j-m] + max(0, T[i] - T[i-m-1]));
	}
	
	printf("%lld\n", dp[n+1][k]);
}
 
int main()
{
	int t;
	t=1;//scanf ("%d", &t);
	while (t--)
		solve();
	return 0;
}

