#include<bits/stdc++.h>
#define ll long long int
#define mk make_pair
#define pb push_back
#define INF (ll)1e18
#define pii pair<ll,ll>
#define mod 1000000007 //998244353
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>b;i--)
#define ff first
#define ss second
#define PI 3.141592653589793238
#define pq priority_queue<ll>
#define pqr priority_queue<ll,vector<ll>,greater<ll>()>
using namespace std;
ll pow_mod(ll a,ll b)
{
	ll res=1;
	while(b!=0)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b/=2;
	}
	return res;
}
void solve()
{
   /*
     A red card with the integer A
     
     A green card with the integer B

     A blue card with the integer  C
   */
   
   // C>B>A
   
   ll a,b,c;
   cin>>a>>b>>c;
   
   ll k;
   cin>>k;
   
   ll mn=0;
   
   while(b<=a){
       b*=2;
       mn++;
   }
   
   while(c<=b){
       c*=2;
       mn++;
   }
   
   if(mn<=k){
       cout<<"Yes\n";
   }
   else
   cout<<"No\n";
   
   
}
int32_t main()
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
//Start from Here.

  ll t;
  t=1;
 // cin>>t;
  while(t--)
  solve();
  
//Good Bye!
    return 0;
}