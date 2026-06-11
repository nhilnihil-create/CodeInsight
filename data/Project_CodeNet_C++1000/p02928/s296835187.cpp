#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
ll mod=1000000007 ;
int main() {
 ll n,k ;
 cin >> n>> k ;
 vector<ll> A(n) ;
 rep(i,n) cin >> A[i] ;
 //sortしてない
 vector<ll> migi(n) ;
 rep(i,n-1){
   rep2(j,i+1,n-1){
     if(A[i]>A[j]) migi[i]  ++ ;
   }
 }
 ll migisum=0 ;
 rep(i,n) migisum+=migi[i] ;
 vector<ll> mog(n) ;
 rep(i,n){
   rep(j,n) if(A[i]>A[j]) mog[i] ++ ;
 }
 ll mogsum =0 ;
 rep(i,n) mogsum+=mog[i] ;
 ll gm= mogsum*((k*(k-1)/2)%mod) ;
 
 cout <<(migisum*k+gm)%mod<<endl ;
     return 0;
}