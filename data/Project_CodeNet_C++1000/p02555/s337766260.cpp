#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i - 3 >= 0) {
            sum += dp[i - 3];
            sum %= MOD;
        }
        dp[i] = sum;
    }

    cout << dp[n] << endl;

    return 0;
}