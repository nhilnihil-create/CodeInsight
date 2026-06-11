#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

const ll INF = 1001002003004005006ll;
ll dp[305][305];

int main() {
    int N, K;
    cin >> N >> K;
    int m = N - K;
    vector<int> h(N);
    rep(i, N) cin >> h[i];
    h.insert(h.begin(), 0);

    // dp[i][j] i個目までの要素を見てi個目を残す,j個残すときの最小コスト
    rep(i, N + 1) rep(j, m + 1) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) { // i:使用する要素
        rep(j, m) { // j: iを使うとき,それまで使用した要素の個数
            ll now = INF;
            rep(k, i) { // k: iの直前の要素がkだった場合
                chmin(now, dp[k][j] + max(0, h[i] - h[k])); // iの直前の壁がkだった場合,iを追加するコストは h[i] - h[k]
            }
            dp[i][j + 1] = now;
        }
    }

    ll ans = INF;
    rep(i, N + 1) chmin(ans, dp[i][m]);
    cout << ans << endl;
}
