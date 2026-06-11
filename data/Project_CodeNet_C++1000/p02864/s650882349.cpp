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
    ll dp[331][331][2];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = INF;
    dp[0][0][1] = h[0];
    dp[0][1][0] = INF;
    dp[0][1][1] = INF;
    int moreZero = (h[0] > 0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (h[i - 1] >= h[i])
            {
                update(dp[i][j][1], dp[i - 1][j][1]);
            } else {
                update(dp[i][j][1], dp[i - 1][j][1] + (h[i] - h[i - 1]));
            }
            for (int last = i - 1; last >= max(0, i - j - 1); last--)
            {
                int toChange = i - last;
                if (j - toChange >= 0) update(dp[i][j][0], dp[last][j - toChange][1]);
                if (j - toChange >= 0) update(dp[i][j][0], dp[last][j - toChange][0]);
                if (h[last] >= h[i])
                {
                    update(dp[i][j][1], dp[last][j - toChange + 1][1]);
                } else {
                    update(dp[i][j][1], dp[last][j - toChange + 1][1] + (h[i] - h[last]));
                }
            }
            if (j >= moreZero) update(dp[i][j][1], h[i]);
//            cerr << "i=" << i << " j=" << j << " dp=" << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
        moreZero += (h[i] > 0);
    }
    ll ans = INF;
    for (int j = 0; j <= k ;j++)
    {
        ans = min({ans, dp[n - 1][j][0], dp[n - 1][j][1]});
    }
    if (moreZero <= k) ans = 0;
    cout << ans;
    return 0;
}
