#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

  ll n;
  cin>>n;
  ll sum=0;
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=n;j++)
    {
      for(ll k=1;k<=n;k++)
      {
        sum+=__gcd(i,__gcd(j,k));
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}