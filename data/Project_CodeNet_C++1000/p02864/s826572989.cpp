#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> h(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1LL << 60));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - k; j++) {
            for(int k = 0; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0LL, h[i] - h[k]));
            }
        }
    }
    ll ans = 1LL << 60;
    for(int i = n - k; i <= n; i++) {
        ans = min(ans, dp[i][n - k]);
    }
    printf("%lld\n", ans);
}