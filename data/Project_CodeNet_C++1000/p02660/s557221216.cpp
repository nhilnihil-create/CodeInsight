#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef pair<ll,ll>pll;
const  ll MAX=100000000;
int main()
{



     ll n;

     cin>>n;

   vector<pll>v;

   ll cnt=0;

   while(n%2==0)
   {
       n/=2;
       cnt++;
   }
   if(cnt)v.eb(2,cnt);

   cnt=0;

   for(ll i=3;i*i<=n;i+=2)
   {
       cnt=0;

       while(n%i==0)
       {
           n/=i;
           cnt++;
       }

       v.eb(i,cnt);
   }
   if(n>1)v.eb(n,1);

   ll ans=0;

  for(auto x:v)
  {
      ll j=2;

      for(ll i=1;i<=x.se;)
      {
        ans++;
        i+=j;
        j++;

      }

  }

  cout<<ans<<endl;




}

