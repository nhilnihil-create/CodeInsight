#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,ll>;
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

int main(){
  ll n; cin>> n ;
  vector<ll> A(n) ;rep(i,n) cin>>A[i] ;
  vector<ll> cnt(n+5) ; rep(i,n) cnt[A[i]]++ ;
  ll ans= 0;
  rep(i,n+5){
    ll a= cnt[i] ;
    ans+= a*(a-1)/2 ;
  }
 rep(i,n) cout<< ans-cnt[A[i]]+1<<endl ;
  return 0;
  }