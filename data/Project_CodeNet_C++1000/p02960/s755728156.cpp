#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const int INF = 2100100100;
const int MOD = 1e9 + 7;

int dp[110000][13];
 
int main() {
    string S;
    cin >> S;
    int len = S.size();
    reverse(S.begin(), S.end());
 
    if (S[0] == '?') {
        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }
    } else {
        int index = S[0] - '0';
        dp[0][index] = 1;
    }
 
    int num = 1;
    for (int i = 1; i < len; i++) {
        num *= 10;
        num %= 13;
 
        if (S[i] == '?') {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    int index = (k + j * num) % 13;
                    dp[i][index] += dp[i - 1][k];
                    dp[i][index] %= MOD;
                }
            }
        } else {
            for (int k = 0; k < 13; k++) {
                int j = (S[i] - '0');
                int index = (k + j * num) % 13;
                dp[i][index] += dp[i - 1][k];
                dp[i][index] %= MOD;
            }
        }
    }
 
    cout << dp[len - 1][5] << endl;
 
    return 0;
}