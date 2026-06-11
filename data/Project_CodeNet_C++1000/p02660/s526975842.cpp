#include<bits/stdc++.h>
#define ll long long int
using namespace std;
unordered_map<ll,ll> mp;
void primes(ll n)
{
  while(n%2==0)
  {
    mp[2]++;
    n=n/2;
  }
  for(ll i=3;i*i<=n;i=i+2)
  {
    while(n%i==0)
    {
      mp[i]++;
      n=n/i;
    }
  }
  if(n>2)
    mp[n]++;

}
int main()
{
  ll n;
  cin>>n;
  primes(n);
  ll ans=0;
  for(const auto& m: mp)
  {
    ll k=1;
    while((m.second*2)/(k*(k+1))>=1)
    {
      k++;
    }
    ans+=k-1;
  }
  cout<<ans<<endl;
}