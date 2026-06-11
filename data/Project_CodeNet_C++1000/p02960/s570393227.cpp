//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


const int MOD = 1e9+7;

void solve() {
    string S; cin >> S;

    vector<vector<int>> dp(S.length(), vector<int>(13));

    if (S[0] == '?') {
        for (int i = 0; i <= 9; i++) {
            dp[0][i] = 1;
        }
    }
    else dp[0][S[0] - '0'] = 1;

    for (int i = 1; i < S.length(); i++) {
        if (S[i] == '?') {
            for (int j = 0; j < 13; j++) {
                for (int k = 0; k <= 9; k++) {
                    dp[i][(j*10 + k)%13] += dp[i-1][j];
                    dp[i][(j*10 + k)%13] %= MOD;
                }
            }
        }
        else {
            for (int j = 0; j < 13; j++) {
                dp[i][(j*10 + S[i]-'0')%13] += dp[i-1][j];
                dp[i][(j*10 + S[i]-'0')%13] %= MOD;
            }
        }
    }

    cout << dp[S.length()-1][5] << endl;
}


int main() {
    solve();
    return 0;
}