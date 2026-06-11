#include "bits/stdc++.h"
using namespace std;

vector<int64_t> prime(int64_t x)
{
  vector<int64_t> pri;
  for(int64_t d=2;d*d<=x;d++)
  {
    if(x%d!=0)
      continue;
    int64_t ex=0;
    while(x%d==0)
    {
      ex++;
      x/=d;
    }
    pri.push_back(ex);
  }
  if(x!=1)
    pri.push_back(1);
  return pri;
}

int64_t tri(int64_t a)
{
  int64_t h;
  for(int64_t i=1;;i++)
  {
    if(a*2<i*(i+1))
    {
      h=i-1;
      break;
    }
  }
  return h;
}

int main()
{
  int64_t n,ans;
  ans=0;
  cin>>n;
  for(int64_t i=0;i<prime(n).size();i++)
  {
    ans+=tri(prime(n).at(i));
  }
  cout<<ans<<endl;
}