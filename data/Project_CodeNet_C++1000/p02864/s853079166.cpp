
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 303;
int n, m;
ll dp[N][N];
ll A[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    if (m >= n) {
        cout << 0 << endl;
        exit(0);
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= n - m; ++k) {
            for (int j = 0; j < i; ++j) {
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + max(0LL, A[i] - A[j]));
            }
        }
    }

    ll res = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        res = min(res, dp[i][n - m]);
    }
    cout << res << endl;

    return 0;
}

