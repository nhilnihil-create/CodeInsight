#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
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
 ll n,k ; cin>>n>>k ;
 if(k<= (n-1)*(n-2)/2){
   ll  x= ((n-1)*(n-2)/2)-k ;
   cout<< (n-1)+ x <<endl ;
   rep(i,n-1){
       cout<<n<<" "<<i+1<<endl ;
   }
   if(x>0){
       bool ok=0 ;
       rep2(i,1,n-2){
           if(ok) break ;
           rep2(j,i+1,n-1){
               x-- ;
               
               cout<< i<< " "<<j<<endl ;
               if(x==0){
                   ok= 1 ;
                   break ;
               }
           }
       }
   }
 }
 else cout<<-1<<endl ;
 return 0 ; 
}

