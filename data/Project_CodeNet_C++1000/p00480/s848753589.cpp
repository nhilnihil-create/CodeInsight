#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
int n,m,dp[101][21],a[101];
main(){
  cin>>n;
  r(i,n)cin>>a[i];
  dp[0][a[0]]++;
  r(i,n-2)r(j,21)if(dp[i][j]){
    int a1=j+a[i+1],a2=j-a[i+1];
    if(a1>=0&&a1<21)dp[i+1][a1]+=dp[i][j];
    if(a2>=0&&a2<21)dp[i+1][a2]+=dp[i][j];
  }
  cout<<dp[n-2][a[n-1]]<<endl;
}