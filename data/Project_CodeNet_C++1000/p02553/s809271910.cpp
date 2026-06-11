#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll l = a*c;
  ll m = a*d;
  ll n = b*c;
  ll o = b*d;
  ll ans = max(max(l,m),max(n,o));
  cout<<ans<<endl;
}

