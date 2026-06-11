#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for(ll i=0;i<n;i++) 
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
  int a,b,m ;
  cin >> a>>b>>m ;
  vector<int> A(a) ;rep(i,a) cin>> A[i] ;
  vector<int> B(b) ;rep(i,b) cin>> B[i] ;
  vector<int> x(m) ;vector<int> y(m) ;vector<int> c(m) ;
  rep(i,m) cin>> x[i]>>y[i]>>c[i] ;
  ll ans=INF ; ll sum= 0;
  rep(i,m){
    sum= A[x[i]-1]+B[y[i]-1] -c[i] ;
    chmin(ans,sum) ;
  }
  sort(A.begin(),A.end()) ;sort(B.begin(),B.end()) ;
  ll poi=A[0]+B[0] ;
  chmin(ans,poi) ;
  cout<< ans <<endl ;
  return 0;
  }