#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

char s[100005];
long long dp[100005][13];

int main() {
    string s;
    cin >> s;
    int n = s.length();

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int c;
        if (s[i] == '?') c = -1;
        else c = s[i] - '0';

        for (int j = 0; j < 10; j++) {
            for (int ki = 0; ki < 13; ki++) {
                if (c != -1 && c != j) continue;
                dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
            }
        }
        for (int j = 0; j < 13; j++) dp[i+1][j] %= MOD;
    }

    long long res = dp[n][5];
    cout << res;
    return 0;
}