#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int t,n,i,j,k=1e9+7,l=0,x=0;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++) cin>>a[i];
  x=a[0];
  for(i=1;i<n;i++)
  {
    if(a[i]<x)
    {
      l+=(x-a[i]);
    }
    else
     x=a[i];
  }
  cout<<l;
}