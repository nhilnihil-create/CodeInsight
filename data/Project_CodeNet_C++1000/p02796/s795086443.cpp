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
  int n ;cin>> n;
    vector<P>  A(n) ;
  rep(i,n){
   ll a,b;
   cin>>a>>b;
   A[i].first=a+b ;
   A[i].second=a-b ;
   }
   sort(A.begin(),A.end()) ;
   ll end=-INF ;
   int ans=0 ;
   rep(i,n){
     if(A[i].second>=end){
       ans++ ;
       end=A[i].first ;
     
     }
   }
    cout << ans << endl;
    return 0;
  }