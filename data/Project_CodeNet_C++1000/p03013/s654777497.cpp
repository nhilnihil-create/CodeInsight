#include <bits/stdc++.h>
using namespace std;

long long int dp[101010];

int main() {
    int n,m; cin>>n>>m;
    vector<bool> ok(101010, true);
    for(int i=0;i<m;++i) {
        int a;cin>>a;
        ok[a] = false;
    }
    
    dp[0] = 1;
    for(int i=0;i<n;++i) {
        if (ok[i+1]) dp[i+1] = (dp[i+1] + dp[i]) % (long long int)(1e9 + 7);
        if (ok[i+2]) dp[i+2] = (dp[i+2] + dp[i]) % (long long int)(1e9 + 7);
    }
    
    // for(int i=0;i<=n;++i) cout << dp[i] << endl;
    cout << dp[n] << endl;
    
    return 0;
}