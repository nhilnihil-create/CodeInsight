#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
const ll INF = 1001001001;
int main()
{
    string s;
    cin >> s;
    vector<ll> a;
    rep(i, s.size())
    {
        a.push_back(s[s.size() - 1 - i] - '0');
    }
    a.push_back(0);
    ll n = a.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    rep(i, n + 1)
    {
        rep(j, 2)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    rep(i, n)
    {
        rep(j, 2)
        {
            ll now = a[i] + j;
            rep(k, 10)
            {
                ll co = k - now;
                if (co < 0)
                {
                    co += 10;
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + k + co);
                }
                else
                {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + k + co);
                }
            }
        }
    }
    cout << dp[n][0] << endl;
}