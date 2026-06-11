#include<bits/stdc++.h>
using namespace std;
#define int long long
#define H (int)998244353
int32_t main() {

    int n, s, i, j;
    cin >> n >> s;
    int a[n];
    for (i = 0; i < n; i++) 
         cin >> a[i];
    int dp[s + 1][n];
    for (i = 0; i < s + 1; i++) {
        for (j = 0; j < n; j++) 
             dp[i][j] = 0;
    }

    dp[0][0] = 2;
    if (a[0] <= s)
        dp[a[0]][0] = 1;

    for (j = 1; j < n; j++) {
         for (i = 0; i <= s; i++) {
              if (dp[i][j - 1] != 0) { 
                  dp[i][j] = (dp[i][j] + (dp[i][j - 1] * 2) % H) %H;
                  if (i + a[j] <= s) {
                      dp[i + a[j]][j] = (dp[i + a[j]][j] + dp[i][j - 1]) % H;
                  } 
              }
         }
    } 
    cout << dp[s][n-1];
    return 0;
}