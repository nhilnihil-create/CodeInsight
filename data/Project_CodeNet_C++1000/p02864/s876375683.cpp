#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e12;
ll dp[305][305];

int main() {
    // dp, N^3が間に合う、dp[j][k] jは最後の列(1-indexed)、kはいくつ削除したのか
    int N, K;
    cin >> N >> K;
    vector<int> H(N+1);
    rep(i, N) cin >> H[i+1];  // 1-indexed
    rep(i, N+1) rep(j, N+1) dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        // iが現在位置
        for (int j = 0; j < i; j++) {
            // jは最後の列
            for (int k = K; k >= 0; k--) {
                // k回削除する
                if (k >= 0) {
                    dp[i][k] = min(dp[i][k], dp[j][k] + max(0, H[i]-H[j])); // i番目をそのまま使う
                }
            }
            for (int k = K+1; k >= 0; k--) {
                if (k - 1 >= 0) {
                    dp[j][k] = dp[j][k-1];
                } else {
                    dp[j][k] = INF;
                }
            }
        }
    }
    ll ans = INF;
    rep(i, N+1) rep(k, K+1) ans = min(ans, dp[i][k]);
    cout << ans << '\n';
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}