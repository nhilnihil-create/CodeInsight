#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e3;
const long long MOD = (long long)1e9 + 7;

int data[N+5];
int datb[N+5];

long long dp[N+5][N+5];

int main() {
    for (int i=0; i<N+3; i++) {
        for (int j=0; j<N+3; j++) {
            dp[i][j] = 1;
        }
    }

    int n,m; scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", data+i);
    for (int j=1; j<=m; j++) scanf("%d", datb+j);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            if (data[i] != datb[j]) {
                dp[i][j] = (dp[i][j] + MOD - dp[i-1][j-1]) % MOD;
            }
        }
    }

    printf("%lld\n", dp[n][m]);
    return 0;
}
