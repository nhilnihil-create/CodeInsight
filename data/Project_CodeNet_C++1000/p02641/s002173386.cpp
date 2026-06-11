#include "bits/stdc++.h"
using namespace std;

int main()
{
  int x,n,ans,a,b;
  cin>>x>>n;
  if(n==0)
  {
    ans=x;
  }
  else
  {
    vector<int> p(n);
    for(int i=0;i<n;i++)
    {
      cin>>p.at(i);
    }
    for(int i=x;i<=101;i++)
    {
      int h=0;
      for(int j=0;j<n;j++)
      {
        if(p.at(j)==i)
        {
          h=1;
          break;
        }
      }
      if(h==0)
      {
        a=i;
        break;
      }
    }
    for(int i=x;i>=-100;i--)
    {
      int h=0;
      for(int j=0;j<n;j++)
      {
        if(p.at(j)==i)
        {
          h=1;
          break;
        }
      }
      if(h==0)
      {
        b=i;
        break;
      }
    }
    if(a-x>=x-b)
      ans=b;
    else
      ans=a;
  }
  cout<<ans<<endl;
}