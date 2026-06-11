#include <bits/stdc++.h>
using namespace std;
const int MD=1e9+7;
int main() {
    int n,m,a[100001],p1;
    long long dp[100001];
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    for (int i=0; i<m; i++) {cin>>p1; a[p1]=1;}
    dp[0]=1;
    for (int i=1; i<=n; i++) {
        if (a[i]) {dp[i]=0; continue;}
        if (i!=1) dp[i]+=dp[i-2];
        dp[i]+=dp[i-1];
        dp[i]%=MD;
    }
    cout<<dp[n]<<'\n';
}