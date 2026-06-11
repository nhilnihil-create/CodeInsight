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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}


int main(){
 ll n ;cin>> n;
 vector<ll> A(n) ; rep(i,n) cin>>A[i] ;
 vector<ll> ans(n) ;
 rep(i,n){
   ll k=n-1-i ;
   ll sum= 0;
   for(ll j=2;j<n+5;j++){
      if(j*(k+1)-1>n-1) break ;
      sum+=ans[(k+1)*j-1] ;
   }
   if( sum%2 != A[k] ) ans[k]=1 ;
 }
 ll cnt=0 ;
 rep(i,n) if(ans[i]==1) cnt++ ;
 cout<<cnt<<endl ;
 rep(i,n) {
   if(ans[i]==1) cout<<i+1<<endl;
 }
 
  return 0 ;
}