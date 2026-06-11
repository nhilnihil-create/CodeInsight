#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2031;
const ll INF = 1e18;

void update(ll& x, ll y)
{
    x = min(x, y);
}
int main()
{
    ll dp[331][331];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    h.emplace_back(0);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = h[0];
    dp[0][1] = INF;
    int moreZero = (h[0] > 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (h[i - 1] >= h[i])
            {
                update(dp[i][j], dp[i - 1][j]);
            } else {
                update(dp[i][j], dp[i - 1][j] + (h[i] - h[i - 1]));
            }
            for (int last = i - 1; last > 0; last--)
            {
                int toChange = i - last - 1;
                if (toChange > j) break;
                if (h[last] >= h[i])
                {
                    update(dp[i][j], dp[last][j - toChange]);
                } else {
                    update(dp[i][j], dp[last][j - toChange] + (h[i] - h[last]));
                }
            }
            if (j >= moreZero) update(dp[i][j], h[i]);
//            cerr << "i=" << i << " j=" << j << " dp=" << dp[i][j] << endl;
        }
        moreZero += (h[i] > 0);
    }
    ll ans = INF;
    for (int j = 0; j <= k ;j++)
    {
        ans = min(ans, dp[n][j]);
    }
    if (moreZero <= k) ans = 0;
    cout << ans;
    return 0;
}
