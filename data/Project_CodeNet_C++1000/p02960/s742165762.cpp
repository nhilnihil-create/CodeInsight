#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;
    reverse(ALL(S));

    ll dp[S.size() + 1][13] = {}; dp[0][0] = 1;
    ll mul = 1;
    REP(i, 0, S.size()) {
        REP(j, 0, 13) {
            if (S[i] == '?') {
                REP(k, 0, 10) {
                    dp[i + 1][(j + (mul * k) % 13) % 13] += dp[i][j];
                    dp[i + 1][(j + (mul * k) % 13) % 13] %= MOD;
                }
            } else {
                int num = (mul * (S[i] - '0')) % 13;
                dp[i + 1][(j + num) % 13] += dp[i][j];
                dp[i + 1][(j + num) % 13] %= MOD;
            }
        }
        mul = (mul * 10) % 13;
    }

    cout << dp[S.size()][5] << endl;
    return 0;
}