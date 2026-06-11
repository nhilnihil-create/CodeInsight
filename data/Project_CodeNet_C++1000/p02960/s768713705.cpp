#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    constexpr int mod = 1e9 + 7;
    
    string S;
    cin >> S;
    
    vector<vector<int>> dp(S.size() + 1, vector<int>(13, 0));
    dp[0][0] = 1;
    rep(i, S.size()) {
        if (S[i] == '?') {
            rep(n, 10) rep(j, 13) {
                dp[i + 1][(j * 10 + n) % 13] += dp[i][j];
                dp[i + 1][(j * 10 + n) % 13] %= mod;
            }
        } else {
            int n = S[i] - '0';
            rep(j, 13) {
                dp[i + 1][(j * 10 + n) % 13] += dp[i][j];
                dp[i + 1][(j * 10 + n) % 13] %= mod;
            }
        }
    }
    cout << dp[S.size()][5] << endl;
    return 0;
}
