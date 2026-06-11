#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
using P = pair<int, int>;

int dp[3001][3001];

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (j >= a[i-1].first) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1].first]+a[i-1].second);
            } else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 0;
    rep(i,n) {
        ans = max(ans, dp[i][t-1] + a[i].second);
    }
    cout << ans << endl;

    return 0;
}