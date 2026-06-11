// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

int power(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) 
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, s; 
        cin >> n >> s;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int dp[n + 5][s + 5];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = power(2, n);
        int inv = power(2, mod - 2);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= s; j++) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                if (j + a[i] <= s) 
                    dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + dp[i][j] * inv) % mod;
            }
        }
     
        cout << dp[n][s] << '\n';
        
    }
    
    return 0;
}

