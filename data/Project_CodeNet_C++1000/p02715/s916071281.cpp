// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

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

int dp[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, k;
        cin >> n >> k;

        // 4 4 4 4... -> ye 1, 2 ke gcd me add ho raha hai
        // Fix : dp[i] -= d[j] for all factors j
        for(int i = 1; i <= k; i++) 
            dp[i] = power(k / i, n);
        for(int i = k; i >= 1; i--) {
            for(int j = 2 * i; j <= k; j += i)
                dp[i] = (dp[i] - dp[j] + mod) % mod;
        }

        int ans = 0;
        for(int i = 1; i <= k; i++) {
            // cout << i << ": " << dp[i] << '\n';
            ans = (ans + i * dp[i]) % mod;
        }
        cout << ans << '\n';
    }
    
    return 0;
}

