#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.1415926535;
const ll MAX=1000000;

ll modpow(ll x,ll y){
  long long ans=1;
  while(y>0){
    if(y&1){
      ans*=x%MOD;
    }
    x*=x%MOD;
    x%=MOD;
    ans%=MOD;
    y>>=1;
  }
  return ans;
}


ll fac[MAX];
ll faci[MAX];

void modCf(){
  fac[0]=1;
  faci[0]=1;
  for(int i=1;i<MAX;i++){
    fac[i]=fac[i-1]*i%MOD;
    faci[i]=modpow(fac[i],MOD-2);
  }
  return;
}

ll modC( ll x,ll y){
  ll ans=fac[x];
  ans*=faci[y]%MOD;
  ans%=MOD;
  ans*=faci[x-y]%MOD;
  return ans%MOD;
}


int main() {
  modCf();
  ll X,Y;
  cin>>X>>Y;
  ll tate=0,yoko=0;
  while(Y>0){
    if(X*4==Y*2){
      yoko=X;
      break;
    }
    X-=2;Y--;
    tate++;
  }
  if(yoko==0&&X!=0){
    cout<<0;
  }
  else{
    cout<<modC(yoko+tate,yoko);
    //cout<<" "<<modC(66666,33333);
  }
}