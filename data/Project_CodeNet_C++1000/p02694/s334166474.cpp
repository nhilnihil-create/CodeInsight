#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll x,ans=0,n=100;
  cin>>x;
  
  while(n<x)
  {
    n+=n/100;
    ans++;
  }
  
  cout<<ans<<"\n";
  return 0;
}