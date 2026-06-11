// 解説見た
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
const int MOD = 1000000007;
int main() {
    string s; cin >> s;
    int dp[100001][13] = {0};
    dp[0][0] = 1;

    rrep(i,s.size()+1) {
        if (s[i-1] == '?') {
            rep(num,10) {
                rep(j,13) {
                    dp[i][(j*10+num) % 13] += dp[i-1][j];
                    dp[i][(j*10+num) % 13] %= MOD;
                }
            }
        }
        else {
            int num = s[i-1] - '0';
            rep(j,13) {
                dp[i][(j*10+num) % 13] += dp[i-1][j];
                dp[i][(j*10+num) % 13] %= MOD;
            }
        }
    }
    cout << dp[s.size()][5] << endl;
}