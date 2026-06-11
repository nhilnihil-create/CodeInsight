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
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> l(n-1);
  for(int i=0;i<n-1;i++)
  {
    l.at(i)=n-i-1;
  }
  for(int x=1;x<=n-1;x++)
  {
    for(int y=x+1;y<=n;y++)
    {
      if(y-x>z(a-x)+z(b-y)+1)
      {
        l.at(y-x-1)--;
        l.at(z(a-x)+z(b-y))++;
      }
    }
  }
  for(int i=0;i<n-1;i++)
  {
    cout<<l.at(i)<<endl;
  }
}