#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define P pair<ll,ll>
#define F first
#define S second
#define all(x)  x.begin() ,x.end()
using namespace std;
const int N=2e3+3;
ll dp[N][N]={0};

int main()
{
  ll n;
  cin>>n;
  vector<P> a(n);
   for(int i=0;i<n;i++){cin>>a[i].F;a[i].S=i;}
    sort(all(a),greater<P>());
   // for(P x:a)cout<<x.F<<" "<<x.second<<"\n";
    
  for(int i=0;i<n;i++)
      for(int  j=0;j<=i;j++){
          int r=i-j;
          dp[i+1][j]=max(dp[i+1][j],dp[i][j]+abs(n-1-r-a[i].S)*a[i].F);
        
          dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+abs(j-a[i].S)*a[i].F);
          
      }
  
  ll ans=0;
  for(int i=0;i<=n;i++)ans=max(ans,dp[n][i]);
  cout<<ans<<"\n";
      


}