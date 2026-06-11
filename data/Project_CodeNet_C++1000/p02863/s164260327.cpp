#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;scanf("%d%d",&n,&t);
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].first,&a[i].second);
    sort(a.begin(),a.end());
    vector<vector<int>> dp(n+1,vector<int>(t));
    vector<int> m(n+1);
    for(int i=n-1;i>=0;i--)m[i]=max(m[i+1],a[i].second);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            if(j<a[i].first)dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-a[i].first]+a[i].second);
        }
        ans=max(ans,dp[i+1][t-1]+m[i+1]);
    }
    printf("%d\n",ans);
}