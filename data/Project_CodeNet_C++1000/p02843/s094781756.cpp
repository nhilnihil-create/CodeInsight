#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
vector<int> vec ;
ll f(ll n){
  if(n==1) return 0 ;
  else if( n==2) return 0 ;
  else if(n==3) return 1 ;
  else return (f(n-1)+f(n-2)+f(n-3))%(10007ll) ;
 }

int main(){
 ll x ;cin>> x ;
 ll syo= x/100ll ; ll amari= x%100ll ;
if(syo*5ll<amari) cout<<0<<endl ;
else cout<<1<<endl ;
  return 0;
  }