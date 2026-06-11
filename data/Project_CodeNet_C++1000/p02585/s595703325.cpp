#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18


int main()
{
  ll n,k;
  cin>>n>>k;
  ll a[n+1];
  ll c[n+1];
  for(ll i=1;i<=n;i++)
      cin>>a[i];
  for(ll i=1;i<=n;i++)
      cin>>c[i];

  ll ans=-inf;
  for(ll i=1;i<=n;i++)
  {
    vector<ll>v;
    v.push_back(0);
    ll sum=c[i];
    ll j=a[i];
    ll len=1;    
    while(j!=i)
    {
      
      sum+=c[j];
      j=a[j];
      len++; 
    }
    ll path=0;
    ll cnt=0;

    while(1)
    {
      cnt++;
      if(cnt>k)
        break;
      path+=c[j];
      j=a[j];
      ll score=path+(max(0ll,sum)*((k-cnt)/len));
      ans=max(ans,score);
      if(i==j)
        break;
    }


    
  }
  cout<<ans<<endl;

  return 0;
}