#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    vector<int>v(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    long long dp[n + 3][s + 3], mod = 998244353;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dp[i][j] = (2 * dp[i - 1][j]) % mod;
        }
        for(int j = v[i]; j <= s; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i]]) % mod;
        }
    }
    cout << dp[n][s];
    return 0;
}