#include <iostream>
using namespace std;
 
int n, s, a, mod = 998244353;
long long dp[3005][3005];
 
int main() {
    cin >> n >> s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        cin >> a;
        for (int j = 0; j <= s; j++){
            dp[i][j] = dp[i-1][j]*2;
            dp[i][j] %= mod;
            if (j >= a){
                dp[i][j] += dp[i-1][j-a];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][s] << "\n";
}