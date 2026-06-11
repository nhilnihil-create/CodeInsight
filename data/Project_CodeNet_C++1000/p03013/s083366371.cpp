#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    const ll MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<bool> oks(n + 1, true);
    rep(i, m) {
        int a;
        cin >> a;
        oks[a] = false;
    }

    vector<ll> dp(n + 1);
    dp[0] = 1;
    rep(i, n) {
        for (int j = i + 1; j <= min(n, i + 2); j++) {
            if (oks[j]) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
