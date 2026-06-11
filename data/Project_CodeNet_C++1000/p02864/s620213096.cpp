#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 303;
const ll Inf = 1000000000000000000ll;

int n, k;
int H[Maxn];
ll dp[Maxn][Maxn][Maxn];

int main()
{
    fill((ll*)dp, (ll*)dp + Maxn * Maxn * Maxn, Inf);
    dp[1][0][0] = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
        for (int j = 0; j < i; j++)
            for (int u = 0; u <= k; u++) if (dp[i][j][u] < Inf) {
                if (u < k) dp[i + 1][j][u + 1] = min(dp[i + 1][j][u + 1], dp[i][j][u]);
                ll add = max(0, H[i] - H[j]);
                dp[i + 1][i][u] = min(dp[i + 1][i][u], dp[i][j][u] + add);
            }
    }
    ll res = Inf;
    for (int j = 0; j <= n; j++)
        for (int u = 0; u <= k; u++)
            res = min(res, dp[n + 1][j][u]);
    printf("%lld\n", res);
    return 0;
}
