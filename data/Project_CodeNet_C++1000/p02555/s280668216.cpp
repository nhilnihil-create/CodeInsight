#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(2001, 0);
    dp[0] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 3; j <= i; ++j) {
            if (dp[i - j]) {
                dp[i] = (dp[i - j] + dp[i]) % mod;
            }
        }
    }
    cout << dp[n] << endl;
}