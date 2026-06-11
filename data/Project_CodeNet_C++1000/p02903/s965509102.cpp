#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main(){
 int h,w ,a ,b;
 cin>> h>>w>>a>>b ;
 if(a*2>w&&b*2>h)
 cout<<"No"<<endl ;
 else{
  rep(i,b){
    rep(j,a) cout<<0 ;
    rep(k,w-a-1) cout<<1 ;
    cout<<1<<endl ;
  }

  rep(i,h-b){
    rep(j,a) cout<<1 ;
    rep(k,w-a-1) cout <<0 ;
    cout <<0<<endl ;
  } 
  } return 0;
}