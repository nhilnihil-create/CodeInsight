//
//  main.cpp
//  E
//
//  Created by 曾憲揚 on 2020/8/19.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e3+5;
pair<int,int> a[maxn];
ll dp[maxn][maxn];

ll solve_dp(int i, int j, int n){
    if(dp[i][j] != -1) return dp[i][j];
    if(j<i) return 0;
    
    int now = j-i+1;
    pair<int, int> p = a[now];
    return dp[i][j] = max(solve_dp(i+1, j, n) + 1LL*p.first*abs(i-p.second),
                          solve_dp(i, j-1, n) + 1LL*p.first*abs(j-p.second));
}

int main(int argc, const char * argv[]) {
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        a[i] = make_pair(x, i);
    }
    sort(a+1, a+n+1);
    
    cout<<solve_dp(1, n, n)<<endl;
    
    return 0;
}
