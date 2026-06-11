#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll dp[n + 1][13] = {};
    dp[0][0] = 1;
    rep(i, 0, n) {
        int x = s[i] - '0';
        rep(j, 0, 13) {
            if (s[i] == '?') {
                rep(k, 0, 10) {
                    dp[i + 1][(j * 10 + k) % 13] += dp[i][j];
                    dp[i + 1][(j * 10 + k) % 13] %= MOD;
                }
            } else {
                dp[i + 1][(j * 10 + x) % 13] += dp[i][j];
            }
        }
    }
    cout << dp[n][5] << endl;
    return 0;
}
