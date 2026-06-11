#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    using Int = long long;
    
    const Int mod = 1000000007;
    
    int n, m;
    cin >> n >> m;
    
    vector<int> s(n), t(m);
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    
    vector<vector<Int>> dp(n + 1, vector<Int>(m + 1));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            (dp[i][j] += dp[i][j - 1]) %= mod;
            (dp[i][j] += dp[i - 1][j]) %= mod;
            
            if (s[i - 1] != t[j - 1]) {
                (dp[i][j] += mod - dp[i-1][j-1]) %= mod;   
            }
        }
    }
    
    cout << dp[n][m] << endl;
}