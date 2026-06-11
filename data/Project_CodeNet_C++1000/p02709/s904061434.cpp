#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e3 + 3;
int dp[N][N], p[N], A[N];

bool cmp(int i, int j) {return A[i] > A[j];}
int32_t main() {
    int n, ans = 0; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i], p[i] = i;
    sort(p + 1, p + n + 1, cmp);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[p[i + j]] * abs(p[i + j] - i));
            if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1] + A[p[i + j]] * abs(p[i + j] - (n - j + 1)));
            if (i + j == n) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}
