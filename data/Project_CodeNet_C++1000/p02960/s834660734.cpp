#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
const int MOD = 1e9 + 7;
const int DIV = 13;
string s;
int dp[NMAX][DIV];

int main()
{
    cin >> s;
    int n = s.size();
    s = "#" + s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '?') {
            for(int j = 0; j <= 9; j++) {
                for(int k = 0; k < DIV; k++) {
                    int rem = (10 * k + j) % DIV;
                    dp[i][rem] = (dp[i][rem] + dp[i - 1][k]) % MOD;
                }
            }
        } else {
            int x = s[i] - '0';
            for(int k = 0; k < DIV; k++) {
                    int rem = (10 * k + x) % DIV;
                    dp[i][rem] = (dp[i][rem] + dp[i - 1][k]) % MOD;
                }
        }
    }
    cout << dp[n][5];
    return 0;
}
