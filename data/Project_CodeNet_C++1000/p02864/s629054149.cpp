#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e15;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> h(n+1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    if(n == k)
    {
      cout << 0 << endl;
      return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-k; j++)
        {
            if(i < j) break;
            for(int x = 0; x <= i-1; x++)
            {
                dp[i][j] = min(dp[i][j], dp[x][j-1] + max(0LL, h[i]-h[x]));
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][n-k]);
    }
    cout << ans << endl;
}
