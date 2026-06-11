#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int x,y;
  cin>>x>>y;
  ll p[4]={0,300000,200000,100000};
  ll ans=0;
  if(x<4)
    ans+=p[x];
  if(y<4)
    ans+=p[y];
  if(x==1 && y==1)
    ans+=400000;
  cout<<ans;
  return 0;
}
