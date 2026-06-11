//
//  main.cpp
//  E
//
//  Created by 曾憲揚 on 2020/9/11.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fr first
#define sc second

const int N=12+1;
const int M=1e3+5;
int cost[M];
int kes[M];

const int INF = 1e9;
int dp[5000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int b;
        cin>>cost[i]>>b;
        for(int j=0; j<b; j++){
            int c; cin>>c;
            kes[i]^=(1<<(c-1));
        }
    }
    
    for(int i=0; i<5000; i++)
        dp[i]=INF;
    
    dp[0]=0;
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<m; j++){
            int to=i|kes[j];
            dp[to]=min(dp[to], dp[i]+cost[j]);
        }
    }
    
    if(dp[(1<<n)-1]!=INF){
        cout<<dp[(1<<n)-1]<<endl;
    }
    else cout<<"-1\n";
    
    return 0;
}

