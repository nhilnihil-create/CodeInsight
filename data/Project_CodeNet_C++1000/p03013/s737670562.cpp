#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[100100];
const int mod = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int a;
        cin >> a;
        dp[a] = -1;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == -1)
            continue;
        if (dp[i - 1] != -1)
        {
            dp[i] += dp[i - 1];
        }
        if (i > 1 && dp[i - 2] != -1)
        {
            dp[i] += dp[i - 2];
        }
        dp[i] %= mod;
    }
    // rep(i, n + 1) cout << i << " : " << dp[i] % mod << endl;
    cout << dp[n] << endl;
    return 0;
}