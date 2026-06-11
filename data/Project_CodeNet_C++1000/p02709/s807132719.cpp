#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, beg, end, step) for (ll i = beg; i < end; i += step)

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> table;
    rep(i, 0, n, 1)
    {
        ll a;
        cin >> a;
        table.push_back({a, i + 1});
    }
    sort(table.rbegin(), table.rend());

    ll dp[n + 1][n + 1];
    dp[0][0] = 0;

    ll i = 0;
    for (pair<ll, ll> p : table)
    {
        i++;
        if (i == 1)
        {
            dp[1][0] = p.first * abs(p.second - n);
            dp[1][1] = p.first * abs(p.second - 1);
            continue;
        }
        rep(j, 0, i + 1, 1)
        {

            if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + p.first * abs(p.second - n + (i - 1));
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + p.first * abs(p.second - j);
            }
            else
            {
                ll m1, m2;
                m1 = dp[i - 1][j - 1] + p.first * abs(p.second - j);
                m2 = dp[i - 1][j] + p.first * abs(p.second - n + (i - 1 - j));
                dp[i][j] = max(m1, m2);
            }
        }
    }
    ll ans = dp[n][1];
    rep(i, 1, n + 1, 1)
    {
        if (dp[n][i] > ans)
        {
            ans = dp[n][i];
        }
    }
    cout << ans << endl;
    return 0;
}