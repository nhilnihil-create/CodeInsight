#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for (ll i = 0; i < N; i++) {
        cin >> H[i];
    }

    //dp[i][j] := 最も右の項の番号がi,サイズがｊであるときのコストの最小値
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, LLONG_MAX / 2));
    dp[0][0] = 0;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            //kからiまでを削除する
            for (ll k = 0; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + max((ll)0, H[i - 1] - (k == 0 ? 0 : H[k - 1])));
            }
        }
    }

    ll ans = LLONG_MAX;
    for (ll i = 0; i <= N; i++) {
        ans = min(ans, dp[i][N - K]);
    }
    cout << ans << endl;
}