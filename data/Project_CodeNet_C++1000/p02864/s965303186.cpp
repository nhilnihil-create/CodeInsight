#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;    // 1.15x10^18
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main() {
    int n, k; cin >> n >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    using vll = vector<long long>;
    vector<vector<vll>> dp(n + 1, vector<vll>(n + 1, vll(k + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int r = 0; r < i; r++) {
            for (int c = 0; c <= k; c++) {
                auto val = dp[i - 1][r][c];
                if (val == INF) continue;
                int cost = max(0, h[i] - h[r]);
                chmin(dp[i][i][c], val + cost);
                if (c < k) chmin(dp[i][r][c + 1], val);
            }
        }
    }
    long long mi = INF;
    for (int r = 0; r <= n; r++) mi = min(mi, dp[n][r][k]);
    cout << mi << endl;
    return 0;
}