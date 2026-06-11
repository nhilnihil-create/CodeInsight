#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll dp[(ll)1e5+1][13];
const ll MOD = (ll)1e9 + 7;

void solve() {
    string s;
    cin >> s;

    dp[0][0] = 1;
    int n = s.size();
    int mul = 1;

    int cnt = 0;
    for (int d = n-1; d >= 0; d--) {
        char c = s[d];
        if (c == '?') {
            rep(i, 10) {
                rep(j, 13) {
                    dp[cnt+1][(i * mul + j) % 13] += dp[cnt][j];
                    dp[cnt+1][(i * mul + j) % 13] %= MOD;
                }
            }
        } else {
            int i = c - '0';
            rep(j, 13) {
                dp[cnt+1][(i * mul + j) % 13] += dp[cnt][j];
                dp[cnt+1][(i * mul + j) % 13] %= MOD;
            }
        }

        mul *= 10;
        mul %= 13;
        cnt++;
    }

    cout << dp[n][5] << endl;
}

int main() {
    solve();
    return 0;
}
