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


int main(){
 double a,b,x ;cin>>a>>b>>x ;
 x= double(x/a) ;
 if(x*2>=a*b){
   double c=a*b-x ;
   double d=double(2*c/a) ;
   double ans= double(atan(double(d/a))*180/pi) ;
   set20 ; 
   cout<<ans<<endl ;
 }
 else{
   double c= double(2*x/b) ;
   double ans= double(atan( double(b/c))*180/pi) ;
   set20 ;
   cout<<ans<<endl ;
 }
 return 0 ; 
}