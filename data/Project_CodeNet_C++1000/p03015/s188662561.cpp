#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

ll dp[101010][2];

int main() {
    string l;
    cin >> l;
    int n = l.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int t = l[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= (j == 0 ? t : 1); k++) {
                if (k == 0) {
                    dp[i + 1][j || k < t] += dp[i][j];
                } else {
                    dp[i + 1][j || k < t] += dp[i][j] * 2LL;
                }
                dp[i + 1][j || k < t] %= MOD;
            }
        }
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}