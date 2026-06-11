#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 5;
const long long mod = 1e9 + 7;

long long dp[mxn][15];

int main() {
    string s;
    cin >> s;
    dp[int(s.size())][0] = 1;
    for (int i = int(s.size()) - 1, ex = 1; i >= 0; i--) {
        if (s[i] == '?') {
            for (int c = 0; c < 10; c++) {
                for (int t = 0; t < 13; t++) {
                    dp[i][(c * ex + t) % 13] += dp[i + 1][t];
                    dp[i][(c * ex + t) % 13] %= mod;
                }
            }
        } else {
            int c = s[i] - '0';
            for (int t = 0; t < 13; t++) {
                dp[i][(c * ex + t) % 13] = dp[i + 1][t];
            }
        }
        ex = (ex * 10) % 13;
    }
    cout << dp[0][5] << endl;
}

