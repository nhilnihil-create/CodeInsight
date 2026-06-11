#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;

int a[3010],dp[3010][3010];

signed main(){
    int n,s;
    cin>>n>>s;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    dp[0][0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            dp[i+1][j]+=2*dp[i][j];
            dp[i+1][j]%=mod;
            if(j+a[i]<=s){
                dp[i+1][j+a[i]]+=dp[i][j];
                dp[i+1][j+a[i]]%=mod;
            }
        }
    }
    
    cout<<dp[n][s]<<endl;
    return 0;
}