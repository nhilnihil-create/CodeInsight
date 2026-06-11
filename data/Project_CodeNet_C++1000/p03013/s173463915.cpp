#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000007;

ll max(ll a, ll b) { return (a > b) ? a : b; }

int main() {
    int n, m;
    cin >> n >> m;
    int *a = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    ll *dp = new ll[n + 10];
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
    }

    // cout << "*********************" << endl;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 0; i < m; i++) {
        if (a[i] == 1) {
            dp[1] = 0;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 == a[j]) {
                dp[i + 1] = 0;
                break;
            }
        }
        dp[i + 2] = (max(dp[i + 2], dp[i] + dp[i + 1])) % MOD;
        // cout << dp[i] << endl;
    }
    // cout << "*****************" << endl;
    cout << dp[n] % MOD << endl;
    return 0;
}