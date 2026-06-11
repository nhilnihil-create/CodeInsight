#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
     string S;
     cin >> S;
     vector<vector<ll>> dp(S.size()+1, vector<ll>(13, 0));
     dp[0][0] = 1;
     for (int i = 0; i < S.size(); i++) {
         for (int j = 0; j < 13; j++) {
             if (S[i] == '?') {
                 for (int k = 0; k < 10; k++) {
                     dp[i+1][(j * 10 + k) % 13] += dp[i][j];
                     dp[i+1][(j * 10 + k) % 13] %= MOD;
                 }
             }
             else {
                 int k = S[i] - '0';
                 dp[i+1][(j * 10 + k) % 13] += dp[i][j];
                 dp[i+1][(j * 10 + k) % 13] %= MOD;
             }
         }
     }
     cout << dp[S.size()][5] << endl;
 }
