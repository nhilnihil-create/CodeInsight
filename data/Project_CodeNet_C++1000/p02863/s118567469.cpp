// 6/25 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int dp[3010][3010];

int main() {
    int N, T;
    cin >> N >> T;
    // vector<int> A(N), B(N);
    // rep(i, N) cin >> A[i] >> B[i];
    vector<P> dish(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        dish[i] = P(a, b);
    }

    sort(dish.begin(), dish.end());

    dp[0][0] = 0;

    int ans = 0;

    rep(i, N) {
        // printf("dish[%d] = %d, %d\n", i, dish[i].first, dish[i].second);
        rep(j, T) {
            dp[i+1][j] = dp[i][j];
            if (j>=dish[i].first) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-dish[i].first]+dish[i].second);
            }
            // printf("dp[%d][%d] = %d\n", i+1, j, dp[i+1][j]);
        }

        int now = dp[i][T-1] + dish[i].second;
        ans = max(ans, now)
;    }

    // cout << dp[N-1][T-1] << endl;
    // cout << dish[N-1].first << endl;

    // cout << dp[N-1][T-1] + dish[N-1].second << endl;
    cout << ans << endl;
}