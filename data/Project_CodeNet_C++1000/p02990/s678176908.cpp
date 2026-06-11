#include<bits/stdc++.h>
using namespace std;
int64_t mod=1000000007;
vector<int64_t> f(2001),fi(2001);
int64_t pw(int64_t x,int64_t y){
  int64_t z;
  if(y==0) return 1;
  else{
    z=pw(x,y/2)*pw(x,y/2)%mod;
    if(y%2==1) z=z*x%mod;
    return z;
  }
}
int64_t cmb(int64_t x,int64_t y){
  int64_t z;
  z=f.at(x)*fi.at(y)%mod;
  z=z*fi.at(x-y)%mod;
  return z;
}
int main() {
  int64_t n,k,i,ans=0;
  cin>>n>>k;
  f.at(0)=1;
  fi.at(0)=1;
  for(i=1;i<=n;i++){
    f.at(i)=f.at(i-1)*i%mod;
    fi.at(i)=fi.at(i-1)*pw(i,mod-2)%mod;
  }
  for(i=1;i<=k;i++){
    if(i<=n-k+1) cout<<cmb(k-1,i-1)*cmb(n-k+1,i)%mod<<endl;
    else cout<<0<<endl;
  }
}