#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
  int a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;
  int res=v*t;
  int res1=w*t;
  int d1=a+res;
  int d2=b+res1;
  int x=res-res1;
  int y=abs(a-b);
  if(x>=y)
  {
    cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }
}