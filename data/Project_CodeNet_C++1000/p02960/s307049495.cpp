#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll dp[100005][13];
const ll MOD = (ll)1e9 + 7;

void solve() {
    string s;
    cin >> s;

    dp[0][0] = 1;
    int n = s.size();
    s.push_back('0');
    reverse(s.begin(), s.end());
    ll mul = 1;
    for (int d = 1; d <= n; d++) {
        char c = s[d];
        if (c == '?') {
            rep(i, 10) {
                rep(j, 13) {
                    dp[d][(i * mul + j) % 13] += dp[d-1][j];
                    dp[d][(i * mul + j) % 13] %= MOD;
                }
            }
        } else {
            rep(j, 13) {
                dp[d][((c - '0') * mul + j) % 13] += dp[d-1][j];
                dp[d][((c - '0') * mul + j) % 13] %= MOD;
            }
        }
        mul *= 10;
        mul %= 13;
    }

    cout << dp[n][5] << endl;
}

int main() {
    solve();
    return 0;
}
