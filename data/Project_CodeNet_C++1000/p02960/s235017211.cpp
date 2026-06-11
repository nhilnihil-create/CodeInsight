#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ar array

const int mod = 1e9 + 7;

const int N = 1e5 + 5;
ll dp[N][13];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    string s;
    cin >> s;
    int n = (int) s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int c = (s[i] == '?') ? -1 : (s[i] - '0');
        for (int j = 0; j < 10; j++) {
            if (c != -1 && c != j) continue;
            for (int r = 0; r < 13; r++) {
                dp[i + 1][(r * 10 + j) % 13] += dp[i][r];
            }
        }
        for (int j = 0; j < 13; j++) {
            dp[i + 1][j] %= mod;
        }
    }
    cout << dp[n][5] << '\n';
}