#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const int mod=1e9+7;

int f(int n,int p){
  if(n==0){return 1;}
  int64_t x=f(n/2,p);x%=mod;
  x*=x;x%=mod;
  if(n%2!=0){x*=p;}
  x%=mod;
  return x;
}
 
int choose(int n,int a){
  int64_t u=1,d=1;
  for(int i=0;i<a;i++){
    u*=n-i;u%=mod;
    d*=i+1;d%=mod;
  }
  return u*f(mod-2,d)%mod;
}

int main() {
  int X,Y;
  cin>>X>>Y;
  if((X+Y)%3!=0){cout<<0<<endl;return 0;}
  int n=(X+Y)/3;
  if(X-n<0||Y-n<0){cout<<0<<endl;return 0;}
  cout<<choose(X-n+Y-n,X-n)<<endl;
  return 0;
}