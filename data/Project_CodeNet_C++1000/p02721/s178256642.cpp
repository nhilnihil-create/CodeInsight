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
 ll n,k, c ;cin>>n>>k>>c ;
 string s; cin>> s; 
 vector<ll> A(k) ;
 ll j=0 ; 
 ll no = 0;
 rep(i,n){
   if(s[i]=='o'&&no==0){
     A[j]=i ;
     no = c ;
     j++ ;
   }
   else{
    if(no>0) no -- ;
   }
   if(j==k) break ;
 }
 reverse(s.begin(),s.end()) ;
 vector<ll> B(k) ;
 j=0 ;
 no=0 ;
 rep(i,n){
   if(s[i]=='o'&&no==0){
     B[j]=i ;
     no = c ;
     j++ ;
   }
   else{
     if(no>0)no -- ;
   }
   if(j==k) break ;
 }

 rep(i,k){
   if(A[i]+B[k-1-i]+1==n) cout<<A[i]+1<<endl ;
 }
   return 0 ;
 }

