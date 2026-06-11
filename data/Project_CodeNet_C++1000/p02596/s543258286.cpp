#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t k,ans,x;
  x=7;
  ans=-1;
  cin>>k;
  for(int i=1;i<=1000000;i++)
  {
    if(x%k==0)
    {
      ans=i;
      break;
    }
    x=(x*10+7)%k;
  }
  cout<<ans<<endl;
}