#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long tab_1[2005], tab_2[2005], dp[2005][2005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
        cin >> tab_1[i];
    for (long long i = 1; i <= m; i++)
        cin >> tab_2[i];
    for (long long i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            dp[i][j] = (long long)dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (tab_1[i] == tab_2[j])
                dp[i][j] = (long long)dp[i][j] + dp[i - 1][j - 1] + 1;
            dp[i][j] %= mod;
            if (dp[i][j] < 0)
                dp[i][j] += mod;
        }
    cout << (dp[n][m] + 1) % mod << "\n";
    return 0;
}