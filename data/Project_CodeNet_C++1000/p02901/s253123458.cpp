#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 12;
const int MAX_M = 1000;

int N, M;
int a[MAX_M + 5], b, d[MAX_M + 5];
int dp[MAX_M + 5][(1<<MAX_N)];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
    {
        scanf("%d%d", &a[i], &b);
        while (b--)
        {
            int c;
            scanf("%d", &c);
            d[i] |= (1<<(c-1));
        }
    }
    dp[0][0] = 0;
    for (int S = 1; S < (1<<N); S++) dp[0][S] = INF;
    for (int i = 1; i <= M; i++)
    {
        for (int S = 0; S < (1<<N); S++)
        {
            dp[i][S] = min(dp[i-1][S], dp[i-1][S&~d[i]]+a[i]);
        }
    }
    if (dp[M][(1<<N)-1] == INF) printf("-1\n");
    else printf("%d\n", dp[M][(1<<N)-1]);
    return 0;
}
