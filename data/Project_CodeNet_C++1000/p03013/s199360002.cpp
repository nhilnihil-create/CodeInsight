#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int main(void){
    int n, m;
    cin >> n >> m;
    
    vector<bool> is_safe(n+1,true);
    
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        
        is_safe[a] = false;
    }
    
    vector<int> dp(n+1,0);
    
    dp[0] = 1;
    if (is_safe[1]) dp[1] = 1;
    
    for (int i = 2; i <= n; i++){
        if (is_safe[i-1]) dp[i] += dp[i-1];
        if (is_safe[i-2]) dp[i] += dp[i-2];
        
        dp[i] %= mod;
    }
    
    cout << dp[n] << endl;
}
