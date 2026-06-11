#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;

int main(){
  int X,Y; cin>>X>>Y;
  
  if((2*Y-X)%3||(2*X-Y)%3||X*2<Y||Y*2<X){
    cout<<0<<endl;
  }else{
    int a=(2*Y-X)/3;
    int b=(2*X-Y)/3;
    if(a<b) swap(a,b);
    
    ll nx=a+1,dx=1,n=1,d=1;
    while(b>0){
      n=n*nx%mod;
      d=d*dx%mod;
      nx++,dx++,b--;
    }
    ll e=mod-2;
    dx=d,d=1;
    while(e>0){
      if(e&1){
        d=d*dx%mod;
      }
      dx=dx*dx%mod;
      e>>=1;
    }
    cout<<n*d%mod<<endl;
  }
}