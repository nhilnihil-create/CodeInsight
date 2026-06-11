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
  int n,l,sum,sa,hi;
  sa=10000;
  sum=0;
  cin>>n>>l;
  vector<int> t(n);
  for(int i=0;i<n;i++)
  {
    t.at(i)=l+i;
    sum+=t.at(i);
  }
  for(int i=0;i<n;i++)
  {
    if(sa>z(t.at(i)))
    {
      sa=z(t.at(i));
      hi=t.at(i);
    }
  }
  cout<<sum-hi<<endl;
}