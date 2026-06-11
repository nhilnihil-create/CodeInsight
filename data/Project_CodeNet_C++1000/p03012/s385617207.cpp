#include "bits/stdc++.h"
using namespace std;

int z(int x)
{
  if(x>=0)
    return x;
  else
    return x*-1;
}

int main()
{
  int n,ans;
  cin>>n;
  ans=10000000;
  vector<int> w(n);
  for(int i=0;i<n;i++)
  {
    cin>>w.at(i);
  }
  for(int i=0;i<n;i++)
  {
    int a,b,c;
    a=0;
    b=0;
    for(int j=0;j<n;j++)
    {
      if(j<=i)
        a+=w.at(j);
      else
        b+=w.at(j);
    }
    c=z(a-b);
    ans=min(ans,c);
  }
  cout<<ans<<endl;
}