#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
  int n;
  cin>>n;
  
  vector <int> dp(1000000+1,0);
  
  for(int i=1;i<=1000000;i++)
  {
    for(int j=i;j<=1000000;j+=i){
    	dp[j]++;
    }
  }
  int ans=0;
  for(int i=1;i<n;i++)
  {
    ans+=dp[n-i];
  }
  
  cout<<ans;
  
  return 0;
}