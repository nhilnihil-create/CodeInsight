#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;cin>>n>>k;
  vector<int> h(n+1,0);
  int i,j,l;
  for(i=1;i<=n;i++)cin>>h.at(i);
  long long ans=0;
  vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
  if(k>=n)ans=0;
  else if(k==0)
  {
    for(i=1;i<=n;i++)ans+=max(0,h.at(i)-h.at(i-1));
  }
  else
  {
    for(i=1;i<=n;i++)
    {
      dp.at(i).at(1)=max(0,h.at(i)-h.at(0));
    }
    for(j=2;j<=n;j++)
    {
      for(i=j;i<=n;i++)
      {
        long long kan=123456789123456;
        for(l=j-1;l<=i-1;l++)
        {
          if(dp.at(l).at(j-1)+max(0,h.at(i)-h.at(l))<kan)
          {
            kan=dp.at(l).at(j-1)+max(0,h.at(i)-h.at(l));
          }
        }
        dp.at(i).at(j)=kan;
      }
    }
      ans=123456789123456;
    for(i=n-k;i<=n;i++)
    {
      ans=min(ans,dp.at(i).at(n-k));
    }
  }
  cout<<ans<<endl;
}
