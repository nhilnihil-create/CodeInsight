#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAX=51000;
const ll MOD=1000000007;
ll fac[MAX],finv[MAX],inv[MAX];
ll extGCD(ll a,ll b,ll &x,ll &y){
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  ll d=extGCD(a,b%a,y,x);
  y-=(a/b)*x;
  return d;
}
void COMtable(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
ll COM(ll n,ll k){
  if(n<k) return 0;
  if(n<0 || k<0) return 0;
  return fac[n]*(finv[n-k]*finv[k]%MOD)%MOD;
}
int main(){
  ll N,K;
  cin >> N >> K;
  ll a[K]={0};
  ll amari=N-K;
  COMtable();
  for(ll i=0;i<K;i++){
    a[i]=COM(amari+1,i+1)*COM(K-1,i)%MOD;
  }
  for(ll i=0;i<K;i++) cout << a[i] << endl;
}
