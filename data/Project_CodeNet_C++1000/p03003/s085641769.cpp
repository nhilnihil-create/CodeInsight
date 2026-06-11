#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m;
    cin>>n>>m;

    int ar[n+2];

    for(int i=1;i<=n;i++)cin>>ar[i];
    int br[m+2];
    for(int j=1;j<=m;j++)cin>>br[j];
    int dp[n+2][m+2];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)dp[i][0] = 1;
    for(int j=1;j<=m;j++)dp[0][j] = 1;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(ar[i]!=br[j])
            dp[i][j] =  dp[i][j-1] + dp[i-1][j] -dp[i-1][j-1];
            else if(ar[i]==br[j]){
                dp[i][j]=(dp[i][j-1] + dp[i-1][j] -dp[i-1][j-1]+dp[i-1][j-1]);
               // cout<<i<<"ded"<<j<<" "<<(dp[i][j-1]+dp[i-1][j])<<endl;
            }
            dp[i][j] =(dp[i][j]%1000000007+1000000007)%1000000007;

           // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][m]<<endl;



    return 0;
}
