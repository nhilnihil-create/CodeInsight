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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

 int main(){
  ll n ;cin>> n;
  vector<P> A(n) ;
  rep(i,n) cin>>A[i].second>>A[i].first ;
  bool ok=1 ;
  sort(A.begin(),A.end()) ;
  ll time=0 ;
  rep(i,n){
   time+=A[i].second ;
   if(A[i].first<time){
      ok=0;
      break ;
   }
  }
   if(ok==1) cout<<"Yes"<<endl ;
    else cout<<"No"<<endl ;
   return 0;
  }