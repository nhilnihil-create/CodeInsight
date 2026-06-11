#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,ans=LONG_LONG_MAX;
  cin>>n;
  for(ll i=1; i*i<=n; i++){
     if(n%i==0){
        ll ans1=n/i;
        ans1=n/i-1+i-1;
        ans=min(ans,ans1);
     }
  }
  cout<<ans;

  return 0;
}