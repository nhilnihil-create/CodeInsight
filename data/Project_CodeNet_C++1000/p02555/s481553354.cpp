#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;

long long dp[669][2002], fp[669][2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int s;
    cin >> s;

    long long ans = 0;
    
    dp[0][0] = 1;

    for (int i=0; i<=s; i++)
        fp[0][i] = 1;
    
    for (int i=1; i<=s/3; i++)
        for (int j=3; j<=s; j++)
        {
            dp[i][j] = fp[i-1][j-3];
            fp[i][j] = (dp[i][j] + fp[i][j-1]) % MOD;
        }

    for (int i=1; i<=s/3; i++)
        ans += dp[i][s];

    cout << ans % MOD << "\n";
    return 0;
}
