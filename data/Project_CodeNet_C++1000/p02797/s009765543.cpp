#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
  int s,n,k;
  cin>>n>>k>>s;
  if(s==1e9)
  {
    for(int i=1;i<=k;i++)
    {
      cout<<s<<' ';
    }
    for(int i=k+1;i<=n;i++)
    {
      cout<<1<<' ';
    }
    cout<<'\n';
  }
  else
  {
    for(int i=1;i<=k;i++)
    {
      cout<<s<<' ';
    }
    for(int i=k+1;i<=n;i++)
    {
      cout<<1000000000<<' ';
    }
    cout<<'\n';
  }
}