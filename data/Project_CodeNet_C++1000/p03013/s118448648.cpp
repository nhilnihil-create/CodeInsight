#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dp(n+1, 0);
    vector<bool> broken(n+1, false);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }

    dp[0] = 1;
    dp[1] = !broken[1];

    for (int i = 2; i <= n; i++) {
        if (!broken[i]) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
    }
    
    cout << dp[n] << endl;
}