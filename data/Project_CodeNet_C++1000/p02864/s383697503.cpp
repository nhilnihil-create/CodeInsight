#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N+2);
    for ( int i = 1; i <= N; i++ ) {
        cin >> H[i];
    }
    const ll INF = 1LL<<60;
    vector<vector<ll>> dp(N+2, vector<ll>(K+1, INF));
    dp[0][0] = 0;
    for ( int n = 1; n <= N+1; n++ ) {
        for ( int k = 0; k <= K; k++ ) {
            for ( int j = 1; j <= min(k+1, n) ; j++ ) {
                ll x = dp[n-j][k-(j-1)] + max(0LL, H[n]-H[n-j]);
                dp[n][k] = min(dp[n][k], x);
            }
        }
    }
    ll ans = dp[N+1][K];
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}