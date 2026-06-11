#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, A;
    cin >> N;
    vector<pair<ll, int>> Ai(N), Bi(N);
    rep(i, N) {
        cin >> A;
        Ai[i] = make_pair(A, i);
    }
    sort(Ai.begin(), Ai.end());
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    rep(i, N) {
        rep(j, i + 1) {
            A = Ai[N - 1 - i].first;
            int k = Ai[N - 1 - i].second;
            //cout << "i=" << i << " A=" << A << " k=" << k << "\n";
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + A * abs(N - 1 - (i - j) - k));
            //cout << "dp[" << i + 1 << "][" << j << "]=" << dp[i + 1][j] << "\n";
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + A * abs(j - k));
            //cout << "dp[" << i + 1 << "][" << j + 1 << "]=" << dp[i + 1][j + 1] << "\n";
        }
    }
    ll ans = 0;
    rep(i, N + 1) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << "\n";
    /*
    rep(i, N + 1) {
        rep(j, N + 1) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
}
