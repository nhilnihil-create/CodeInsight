#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, INF));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            if (j < a[i])
            {
                dp[i + 1][j] = min(dp[i][j], ((j + a[i] - 1) / a[i]) * b[i]);
            }
            else
            {
                dp[i + 1][j] = min(dp[i + 1][j - a[i]] + b[i], min(dp[i][j], (j + a[i] - 1) / a[i] * b[i]));
            }
        }
    }
    // for (auto line : dp)
    // {
    //     print(line);
    // }
    cout << dp[n][h] << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}