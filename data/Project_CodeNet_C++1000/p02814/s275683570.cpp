#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
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
 ll n,m ;cin>> n>>m ;
 vector<ll> A(n) ;rep(i,n) cin>>A[i] ;
 vector<ll> ord(n) ;
 rep(i,n){
     while(A[i]%2==0){
         A[i]/=2 ;
         ord[i]++ ;
     }
 }
 bool ok=1 ;
 rep(i,n-1){
     if(ord[i]!=ord[i+1]) ok=0 ;
 }
 if(ok){
  ll ans=1ll ;
  rep(i,n){
      ans= lcm(ans,A[i]) ;
  }
  ans = ans* pow(2,ord[0]-1) ;
 ll bns= m/ans ;
 cout<< (bns+1)/2 <<endl ;
 }
 else cout<<0<<endl ;
 return 0 ; 
}