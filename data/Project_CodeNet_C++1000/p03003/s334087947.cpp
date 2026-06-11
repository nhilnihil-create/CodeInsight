#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 2005, mod = 1e9 + 7;
int n, m, a[N], b[N], dp[N][N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            (dp[i][j] += dp[i-1][j] + dp[i][j-1]) %= mod;
            (dp[i][j] += mod - dp[i-1][j-1]) %= mod;
            if(a[i] == b[j]) (dp[i][j] += dp[i-1][j-1] + 1) %= mod;  
        }
    }
    cout << (dp[n][m] + 1) % mod;
}