#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    vector<pair<long long,long long>>p(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        p[i]={a[i],i};
    }
    sort(p.begin(),p.end(),greater<pair<long long,long long>>());
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1000000000000000000));//左に何人、右に何人いるか
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            if(i<n)dp[i+1][j]=max(dp[i+1][j],dp[i][j]+p[i+j].first*abs(p[i+j].second-i));
            if(j<n)dp[i][j+1]=max(dp[i][j+1],dp[i][j]+p[i+j].first*abs(n-j-1-p[i+j].second));
        }
    }
    long long m=0;
    for(int i=0;i<=n;i++)for(int j=0;i+j<=n;j++)m=max(m,dp[i][j]);
    cout<<m<<endl;
    return 0;
}