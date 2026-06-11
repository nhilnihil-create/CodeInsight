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
#define fi first 
#define se second 
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
 
//隣のきゃくは客はようよく柿食う客だ
//垢巻紙赤巻紙青牧蒼秋神青巻紙木巻紙黄巻紙 
int main(){
 ll n,m ;
 cin>> n>>m ;
 vector<P> A(n) ;
 rep(i,n) cin>> A[i].first>>A[i].second ;
 sort(A.begin(),A.end()) ;
 //後ろから見るm日目から
 priority_queue<ll> q ;
 ll ans=0 ;
 ll x=0 ;
 rep(i,m+1){
  
   while(x<=n-1&&A[x].first<=i){
     q.push(A[x].se) ;
     x++ ;
   }
   if(!q.empty()){
     ans+= q.top() ;
     q.pop() ;
   } 
 }
  cout<<ans<<endl ;
  return 0;
  }