#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
ll s[2005],t[2005],dp[2005][2005];
ll M=1000000007;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
        //dp[i][0]=1;
    }
    for(int i=0;i<m;i++){
        cin>>t[i];
        //dp[0][i]=1;
    }
    //dp[n][0]=1; dp[0][m]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%M;
            }else{
                dp[i][j]=(-dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1])%M;
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    if(dp[n][m]+1<0){
        cout<<dp[n][m]+1+M<<endl;
    }else{
        cout<<dp[n][m]+1<<endl;
    }
    
    
}
