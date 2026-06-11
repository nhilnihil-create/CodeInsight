#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int n,m;
    cin>>n>>m;
    int item_v[100],item_w[100];
    rep(i,n){
        cin>>item_v[i]>>item_w[i];
    }
    
    int dp[101][10100]={};
    for(int i=1;i<=n;i++){
        rep(j,10001){
            dp[i][j] = dp[i-1][j];
            
            if( j-item_w[i-1]>=0 ){
                dp[i][j] = max( dp[i][j] , dp[i-1][j-item_w[i-1]] + item_v[i-1] );
            }
        }
    }
    int maximum = -1;
    rep(j,m+1){
        maximum = max( maximum , dp[n][j] );
    }
    cout<<maximum<<endl;
}