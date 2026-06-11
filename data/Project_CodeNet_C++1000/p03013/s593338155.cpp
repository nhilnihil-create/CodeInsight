#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<bool> stairs(n+1, true);
    for (size_t i = 0; i < m; i++) {
        int a;
        cin >> a;
        stairs[a] = false;
    }

    vector<long long> dp(n+1);
    dp[0] = 1;
    for (size_t i = 0; i <= n; i++) {
        if (stairs[i+1]) {
            dp[i+1] += dp[i];
            dp[i+1] %= 1000000007;
        }
        if (stairs[i+2]) {
            dp[i+2] += dp[i];
            dp[i+2] %= 1000000007;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
