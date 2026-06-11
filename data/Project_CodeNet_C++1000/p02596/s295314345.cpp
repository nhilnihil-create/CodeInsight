#include<bits/stdc++.h>
using namespace std;
int main()
{
  int k;
  cin>>k;
  vector<int>dp(10000000);
  long long int ans=1;
  long long int mod=0;
  while(true)
  {
    long long int mod=((mod*10)+7)%k;
    if(mod==0)
    {
      cout<<ans;
      break;
    }
    else if(dp[mod])
    {
       cout<<"-1";
      break;
    }
    dp[mod]=1;
    
    ans++;
  }
  return 0;
}