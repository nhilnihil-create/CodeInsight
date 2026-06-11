#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e12;
ll dp[2005][2005];

int main() {
    // 貪欲ではダメそう、右に移動するものと左に移動するもの、DP
    // dp[i][j] 左はi個決めて、右はj個決める
    // 大きい活発度から左右に入れる場合、O(N^2)でも大丈夫
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<P> que;
    rep(i, N) que.emplace_back(A[i], i);
    sort(que.begin(), que.end());
    rep(i, N+2) rep(j, N+2) dp[i][j] = INF;
    dp[0][0] = 0;
    int people = 0;
    while (!que.empty()) {
        people++;
        auto p = que.back(); que.pop_back();
        int move = p.first, ind = p.second;
        // 左に入れる
        {
            for (int i = 1; i <= N; i++) {
                int right = people - i; // 右にいる人
                if (right < 0) break;
                int left = i-1; // 左にいた人
                if (dp[left][right] == INF) break; // 不可能
                if (dp[i][right] == INF) {
                    dp[i][right] = dp[left][right] + (ll)move * abs(ind - (i-1));
                } else {
                    dp[i][right] = max(dp[i][right], dp[left][right] + (ll)move * abs(ind - (i-1)));
                }
            }
        }
        // 右に入れる
        {
            for (int i = 1; i <= N; i++) {
                int left = people - i; // 左にいる人
                if (left < 0) break;
                int right = i-1; // 右にいた人
                if (dp[left][right] == INF) break; // 不可能
                if (dp[left][i] == INF) {
                    dp[left][i] = dp[left][right] + (ll)move * abs(ind - ((N-1)-(i-1)));
                } else {
                    dp[left][i] = max(dp[left][i], dp[left][right] + (ll)move * abs(ind - ((N-1)-(i-1))));
                }
            }
        }
    }
    ll ans = 0;
    rep(i, N) ans = max(ans, dp[i][N-i]);
    cout << ans << '\n';
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}