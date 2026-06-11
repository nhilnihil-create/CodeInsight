#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<P> B(n);
    rep(i, n) {
        cin >> A[i];
        B[i] = P(A[i], i);
    }
    sort(B.rbegin(), B.rend());
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    rep(i, n) rep(j, i+1) {
        dp[i+1][j] = max(dp[i][j] + (ll)B[i].first * abs(n-1-(i-j)-B[i].second), dp[i+1][j]);
        dp[i+1][j+1] = dp[i][j] + (ll)B[i].first * abs(B[i].second - j);
    }
    ll ans = 0;
    rep(i, n+1) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}