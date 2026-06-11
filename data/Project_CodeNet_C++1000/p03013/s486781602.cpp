#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n+1, 0);
    rep(i,m) {
        int t;
        cin >> t;
        b[t] = 1;
    }

    vector<int> dp(n+2);
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        if (b[i] == 1) {
            dp[i] = 0;
            continue;
        }

        dp[i] = (dp[i+1] + dp[i+2]) % 1000000007;
    }

    cout << dp[0] << endl;

    return 0;
}