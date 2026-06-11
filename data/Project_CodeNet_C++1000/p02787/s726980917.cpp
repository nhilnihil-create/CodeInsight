#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1000000000;
 
int main() {
    int h,n;
    cin>>h>>n;
    ll dp[1010][10010];
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    
    }
    for(int i=0;i<1010;i++){
        for(int j=0;j<10010;j++){
            dp[i][j]=inf;
        }
    
    }
  	dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=h;j++){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            dp[i][(j+a[i])<=h?(j+a[i]):h]=min(dp[i][j]+b[i],dp[i][(j+a[i])<=h?(j+a[i]):h]);
        }
    }    
    cout<<dp[n-1][h]<<endl;
}