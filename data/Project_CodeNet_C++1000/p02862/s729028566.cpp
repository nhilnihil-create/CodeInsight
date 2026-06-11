#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2100000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void init(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

ll nCr(int n,int k){
  if(n<k) return 0;
  if(n<0 || k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main() {
  init();
  ll x,y;
  cin>>x>>y;
  
  if((2*x-y)%3!=0 || (2*y-x)%3!=0){
    cout<<0<<endl;
    return 0;
  }
  
  ll a=(2*x-y)/3;
  ll b=(2*y-x)/3;
  cout<<nCr(a+b,a)<<endl;
  
  return 0;
}