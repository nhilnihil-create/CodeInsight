#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  ll n,a,b;
  cin>>n>>a>>b;
  if(a==0)
  {
    cout<<0<<endl;
  }
  else
  {
    ll t=a+b;
    ll ans=n/t;
    ll rem=n%t;
    if(rem>a)
    {
      cout<<ans*a+a<<endl;
    }
    else
    {
      cout<<ans*a+rem<<endl;
    }
  }
  return 0;
}