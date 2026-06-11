#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i+1];

    vector<ll> dp(n+1);
    dp[0] = 1000;
    for (int k = 1; k <= n; k++) {
        dp[k] = 0;
        for(int i = 0; i < k-1; i++) {
            int m = 99999;
            for(int j = i+1; j < k; j++) {
                m = min(m, a[j]);
            }
            dp[k] = max(dp[k], dp[i]/m*a[k] + dp[i]%m);           
        }
    }
    ll ans = 0;
    rep(i, n+1) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0; 
}