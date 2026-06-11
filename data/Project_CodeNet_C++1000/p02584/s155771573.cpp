#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<ll>
#define pb push_back
#define ff first
#define ss second
#define inf 2e18
#define ull unsigned long long
#define pi acos(-1.0)
#define mod 1000000007
#define lop0(n) for(ll i=0;i<n;i++)
#define lopj(n) for(ll j=0;j<n;j++)
#define lop1(n) for(ll i=1;i<=n;i++)
#define all(v) v.begin(),v.end()
ll Set(ll N,ll pos){ return N=N | (1LL<<pos); }
ll reset(ll N,ll pos){ return N= N & ~(1LL<<pos); }
bool check(ll N,ll pos){ return (bool)(N & (1LL<<pos)); }
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

main()
{
   ll x,k,d;
   cin>>x>>k>>d;
   ll xx=abs(x);
   ll lagbe=xx/d;
   k-=lagbe;
   if(k<=0)
   {
       k+=lagbe;
       cout<<xx-k*d;
       return 0;
   }
   if(x<0)
   {
       x+=(lagbe*d);
   }
   else if(x>0)
   {
        x-=(lagbe*d);
   }
   if(x==0)
   {
       if(k%2) cout<<d;
       else cout<<0;
       return 0;
   }

   if(k%2)
   {
       if(x>0) cout<<abs(x-d);
       else cout<<x+d;
   }
   else cout<<abs(x);



}

