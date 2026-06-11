#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n,k;
    cin>>n>>k;
    if(n-k==0){
        cout<<0<<endl;
        return 0;
    }
    ll dp[n-k][n];
    fill(dp[0],dp[n-k],LINF);
    for(int i=0;i<n;i++){
        cin>>dp[0][i];
    }
    for(int i=1;i<n-k;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i-1][k]+max(0LL,dp[0][j]-dp[0][k]));
            }
        }
    }
    ll ans=LINF;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[n-k-1][i]);
    }
    cout<<ans<<endl;
}