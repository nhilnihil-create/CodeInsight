#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
 
 int main(){
  ll  n ; cin>> n ;
  ll nd = n ;
  ll ko=0 ;
  while(nd%2==0){
    nd/=2 ;
    ko++ ;
  }
  ll base = pow(2,ko) ;
  ll aase = n-base ;
  if(nd==1||n<=2) cout<< "No"<<endl ;
  else{
    cout<<"Yes"<<endl ;
    ll k= (n-1)/2 ;
    rep(i,k){
      ll p= 2*(i+1) ;
      cout<<p<<" "<<p+1<<endl ;
      cout<<p+1<<" "<<1<<endl ;
      cout<<1<<" "<<p+n<<endl ;
      cout<<p+n<<" "<<p+1+n<<endl ;
    }
     cout<<n+1<<" "<<2<<endl ;
   if(n%2==0){
     cout<<base+1<<" "<<n<<endl ;
     cout<<aase+n<<" "<<2*n<<endl;
   }

  }
   return 0 ;
 }

