//#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3000 + 50;
const int mod = 1e9 + 7;
int n,k;
int h[N];
ll dp[N][N];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", h + i);
    if (n == k)
    {
        puts("0");
        return 0;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int l = 1; l <= n - k; ++l)
            for (int j = 0; j < i; ++j)
                dp[i][l] = min(dp[i][l], dp[j][l - 1] + max(0, h[i] - h[j]));
    ll ans = 1e18;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, dp[i][n - k]);
    printf("%lld\n", ans);
    return 0;
}
