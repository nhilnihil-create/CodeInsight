#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i].first >> D[i].second;
    }
    sort(D.begin(), D.end());

    vector<vector<int>> dp(N, vector<int>(T, 0));
    if (D[0].first < T) {
        dp[0][D[0].first] = D[0].second;
    }
    for (int i = 1; i < N; i++) {
        for (int t = 0; t < T; t++) {
            dp[i][t] = dp[i - 1][t];
            if (D[i].first <= t) {
                dp[i][t] = max(dp[i][t], dp[i - 1][t - D[i].first] + D[i].second);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int t = 0; t < T; t++) {
            temp = max(temp, dp[i][t]);
        }
        if (i != N - 1) {
            temp += D[i + 1].second;
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
