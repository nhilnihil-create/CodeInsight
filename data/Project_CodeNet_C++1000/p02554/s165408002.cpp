#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long
ll powi(ll a,ll n)
{
  ll ans=1;
  while(n)
  {
    if(n%2)ans*=a, ans%=mod;
    a*=a;
    a%=mod;
    n=n/2;
  }
 
  return ans;
}

int main()
{
  ll n;
  cin>>n;
  ll ans=powi(10,n)-powi(9,n)-powi(9,n)+powi(8,n);
  ans%=mod;
  ans+=mod;
  ans%=mod;
  cout<<ans<<endl;
  return 0;
}
