#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int n;
int s;
int a[30001];
const long long Mod = 998244353;
long long dp[3001][3001];
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //-------------------------------
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = (2 * dp[i - 1][j]) % Mod;
            if (j >= a[i])
            {
                dp[i][j] += dp[i - 1][j - a[i]];
                dp[i][j] %= Mod;
            }
        }
    }
    cout << dp[n][s];
    return 0;
}