//
//  main.cpp
//  F
//
//  Created by 曾憲揚 on 2020/8/11.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;
const int MOD = 998244353;
int a[maxn];

long long dp[maxn][maxn];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, s; cin >> n >> s;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=s; j++){
            dp[i][j] += (2*dp[i-1][j]);
            dp[i][j] %= MOD;
            
            if(j+ a[i] <= s){
                dp[i][j + a[i]] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
    }
    
    cout << dp[n][s] << endl;
    
    return 0;
}
