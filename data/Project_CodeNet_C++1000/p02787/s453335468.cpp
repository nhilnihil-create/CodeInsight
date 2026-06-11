#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<ll> dp(h + 1, INT32_MAX);
    dp[0] = 0;

    for (int i = 1; i <= h; ++i)
    {
        rep(j, n)
        {
            dp[i] = min(dp[i], dp[max(i - a[j], 0)] + b[j]);
        }
    }
    cout << dp[h] << endl;
}