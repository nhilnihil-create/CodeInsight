#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
#define mod 1000000007
int dp[MAXN][13];   
int nanjou[6];
int main () {
    nanjou[0] = 1;
    nanjou[1] = 10;
    nanjou[2] = 9;
    nanjou[3] = 12;
    nanjou[4] = 3;
    nanjou[5] = 4;
    string s;
    cin >> s;
    memset(dp, 0, sizeof(dp));
    int n = s.length();
    if (s[n - 1] == '?') {
        for (int i = 0; i < 10; i++) {
            dp[n - 1][i] = 1;
        }
    }
    else {
        dp[n - 1][s[n - 1] - 48] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '?') {
            int jou = (n - 1 - i) % 6;
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k + j * nanjou[jou]) % 13] = (dp[i][(k + j * nanjou[jou]) % 13] + dp[i + 1][k]) % mod;
                } 
            }
        }
        else {
            int jou = (n - 1 - i) % 6;
            for (int k = 0; k < 13; k++) {
                dp[i][(k + (s[i] - 48) * nanjou[jou]) % 13] = (dp[i][(k + (s[i] - 48) * nanjou[jou]) % 13] + dp[i + 1][k]) % mod;
            } 
        }
    }
    cout << dp[0][5] << endl;
    return 0;
}