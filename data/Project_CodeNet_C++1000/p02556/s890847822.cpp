#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
using namespace std;
using namespace __gnu_pbds;
 	// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inff (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define SPEED ios_base::sync_with_stdio(false) ;cin.tie(NULL) ;cout.tie(NULL) ;
#define fp(i,a,n) for(ll i=n-1; i>a ;i--)
#define deb(x) cout << #x << " ---> " << x << endl;
#define X first
#define Y second
#define pia 3.1415926536
#define mod 1000000007

#define ml map<ll,ll>
#define mll map<pll,ll>
#define vvl vector<vl>
#define letsh(a,b) a<<b
#define rigsh(a,b) a>>b
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count()) ; 
		ll lcm(ll a, ll b){
	       return a / __gcd(a, b) * b;
	    }
	   bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 	   

          ll power(ll a,ll n)
	   {
        ll ans=1;
        while(n)
		{
        if(n&1) ans=(ans*a);
        a=(a*a) ;
        n=n>>1;
   		 }
   		 return ans;
      }
      ll power2(ll a,ll n)
      {
      	ll ans =1 ;
      	while(n)
      	{
      		if(n&1) ans =(ans*a) ;
      		a = (a*a) ;
      		n =n>>1 ;
		  }
		  return ans ;
	  }
	  vvl dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) ;
 #define N 500050
    ll add(ll a,ll b)
    {
    	a = (a+b )%mod ;
    	if(a <0) a+=mod ;
    	
    	return a ;
	}
   ll mul(ll a, ll b)
   {
   	a *= b ;
   	return a%mod ;
   }
    vl fre(N,0) ; ll n ,k,d ;
    void upd(ll x ,ll val )
	    {
	    	for(int i = x; i<= N ;i |=(i+1)) fre[i] +=val ;
		}

	ll sum(ll x)
		{
			ll ans = 0 ;
			for(int i = x;i>=0 ;i =(i&(i+1))-1 ) ans +=fre[i] ;
			return ans ;
		}
	 ll dif(ll x,ll y)
	 {
	 	return sum(x) -sum(y-1) ;
	 }
	 void solve()
		 {
		 	ll n ;cin>>n ;
		 	vll a(n) ; 
			 f(i,0,n) cin>>a[i].X>>a[i].Y ;
		 	 ll ans = -1LL*mod*mod ;
			 vl mx(n,100LL*mod) ;
			 sort(all(a)) ;
			 mx[0] = a[0].X +a[0].Y ;
			 vl mx1(n) ;
			 mx1[0] = -a[0].X +a[0].Y ;
		 	f(i,1,n)
		 	{
		 		ans = max({ans, a[i].X -a[i].Y + mx1[i-1] ,a[i].X +a[i].Y -mx[i-1]}) ; ;
			     mx[i] = min(mx[i-1] ,a[i].X +a[i].Y) ;
			    mx1[i] = max(mx1[i-1] ,-a[i].X +a[i].Y) ;
			 }
		  cout<<ans<<endl ; 	
		  
		  
		  } 
	  int main() 
	  	{
	  	    SPEED 
	  	    ll t =1 ;
	  	    while(t--) solve() ;
		}