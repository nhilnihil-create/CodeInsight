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

  ll n,m;
  cin>>n>>m;
  vector<ll> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    a[i]=a[i]/2;
  }

  ll lcm=a[0];

  ll prev;

  for(int i=1;i<n;i++)
  {
    prev=lcm;
    lcm=(lcm*a[i])/(__gcd(lcm,a[i]));
    if(lcm<prev)
    {
      cout<<0<<endl;
      return 0;
    }
    if((lcm/a[i])%2==0)
    {
      cout<<0<<endl;
      return 0;
    }

  }




  ll ans=(m/(lcm));

  long double div=2;

  ans=ceil(ans/div);

  cout<<ans;
  
  

  return 0;
}