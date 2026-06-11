#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll inf = 1e18;

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> H(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> H[i];
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, inf)); //dp[i][j] = i個塗ってjを最後とする
    dp[0][0] = 0;
    
    if (N == K) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = 0; k <= i-1; k++) {
                dp[j][i] = min(dp[j][i], dp[j-1][k]+max((ll)0, H[i]-H[k]));
            }
        }
    }
    ll ans = 1e18;
    for (int i = N-K; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans = min(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
