#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t h,ans,t;
  cin>>h;
  ans=0;
  t=1;
  while (h>0)
  {
    ans+=t;
    t*=2;
    h/=2;
  }
  cout<<ans;
}