#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll dp[310][310][310];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<ll> h(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < 310; i++)
    {
        for (int j = 0; j < 310; j++)
        {
            for (int l = 0; l < 310; l++)
            {
                dp[i][j][l] = LLINF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int l = 0; l <= k; l++)
            {
                chmin(dp[i + 1][j][l+1], dp[i][j][l]);
                chmin(dp[i + 1][i + 1][l], dp[i][j][l] + max(0LL, h[i + 1] - h[j]));
            }
        }
    }
    ll ans = LLINF;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            chmin(ans, dp[n][i][j]);
        }
    }
    cout << ans << endl;
}