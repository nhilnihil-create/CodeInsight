#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
    for (int i = 0; i < N; i++) {
        dp[0][i+1] = dp[0][i] + abs(N-1-i-A[i].second) * A[i].first;
        dp[i+1][0] = dp[i][0] + abs(A[i].second-i) * A[i].first;
        for (int j = 1; j <= i; j++) {
            dp[j][i+1-j] = max(dp[j-1][i+1-j] + abs(j-1-A[i].second) * A[i].first, dp[j][i-j] + abs(N-i-1+j - A[i].second) * A[i].first);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= N; i++) ans = max(ans, dp[i][N-i]);
    cout << ans << endl;
    return 0;
}