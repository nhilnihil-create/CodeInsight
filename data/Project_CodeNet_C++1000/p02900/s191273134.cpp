#include "bits/stdc++.h"
using namespace std;

int64_t gcm(int64_t x,int64_t y)
{
  if(x%y==0)
   return y;
  return gcm(y,x%y);
}

int main()
{
  int64_t a,b,c,d,ans;
  ans=1;
  cin>>a>>b;
  c=gcm(a,b);
  d=c;
  if(c!=1)
  {
    for(int64_t i=2;i<=sqrt(d);i++)
    {
      if(c%i==0)
      {
        ans++;
        while(c%i==0)
        {
          c=c/i;
        }
      }
    }
    if(c!=1)
      ans++;
  }
  cout<<ans<<endl;
}