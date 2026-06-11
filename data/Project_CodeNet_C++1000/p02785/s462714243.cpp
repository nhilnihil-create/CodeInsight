#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h[200010],n,k;
bool cmp(ll a,ll b)
{
  return a>b;
}
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>h[i];
  sort(h,h+n+1,cmp);
  ll ans=0;
  for(int i=k;i<=n;i++)
    ans+=h[i];
  cout<<ans;
  return 0;
}
