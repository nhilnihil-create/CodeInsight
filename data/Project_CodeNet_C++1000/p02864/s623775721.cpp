#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300 + 7;
const ll INF = (ll) 1e18;
int n;
int k;
int a[N];
ll dp[N][N]; /// dp[last][cnt]

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    k = n - k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = a[i];
    }
    ll ans = INF;
    for (int c = 1; c < k; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                dp[j][c + 1] = min(dp[j][c + 1], dp[i][c] + max(0, a[j] - a[i]));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][k]);
    }
    cout << ans << "\n";
}
