#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
 ll x,k,d;
  cin>>x>>k>>d;
  x=abs(x);
  ll ans=x/d; ll ans1=x%d;
  if(ans<=k)
  { k=k-ans;
   if(k&1)
  { cout<<min(abs(ans1-d),abs(ans1+d));
  }
  else cout<<ans1;}
  else
  {cout<<x-(k*d);
  }
}