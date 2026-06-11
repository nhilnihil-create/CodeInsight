#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int f(int n,int p){
  if(n==0){return 1;}//cout<<1<<endl;
  int64_t x=f(n/2,p);x%=mod;
  x*=x;x%=mod;//二乗している
  if(n%2!=0){x*=p;}
  x%=mod;//cout<<x<<" "<<x%mod<<endl;
  //cout<<x<<endl;
  return x;
}

int choose(int n,int a){
  int64_t u=1,d=1;
  for(int i=0;i<a;i++){
    u*=n-i;u%=mod;
    d*=i+1;d%=mod;
  }//int z=mod;cout<<z<<endl;
  //cout<<u%mod*f(mod-2,d)%mod<<endl;
  //cout<<u<<" "<<d<<endl;
  return u*f(mod-2,d)%mod;
}

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  int ALL=f(n,2)-1;
  ALL-=choose(n,a);if(ALL<0){ALL+=mod;}
  ALL-=choose(n,b);if(ALL<0){ALL+=mod;}
  cout<<ALL<<endl;
  return 0;
}