#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n; ll x; ll t;
  cin>>n>>x>>t;
  ll ans=n/x;
  if(n%x!=0)
    ans+=1;
  cout<<ans*t;
  return 0;
}
  
