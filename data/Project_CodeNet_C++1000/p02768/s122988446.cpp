#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MAX=550000;
ll fanc[MAX],inv[MAX],finv[MAX];
void COMinit(){
  fanc[0]=fanc[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fanc[i]=fanc[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
int COM(int a,int b){
  if(a<b)return 0;
  if(a<0||b<0)return 0;
  return (fanc[a]*finv[a-b]%MOD)*finv[b]%MOD;
}
ll Repeat(int N,int M,int P){
  if(M==0)return 1;
  if(M%2==0){
    ll t=Repeat(N,M/2,P);
    return t*t%MOD;
  }
  return Repeat(N,M-1,P)*N;
}

int main(){
 COMinit();
 ll N,a,b;
 cin>>N>>a>>b;
ll all=Repeat(2,N,MOD);
ll v1=1;
ll v2=1;
for(ll i=N;i>=N-a+1;i--){
  v1=v1*i;
  v1%=MOD;
}
for(ll i=N;i>=N-b+1;i--){
  v2=v2*i;
  v2%=MOD;
}
ll nCa=v1*finv[a]%MOD;
ll nCb=v2*finv[b]%MOD;
//cout<<<<endl;
//cout<<v2<<endl;
ll ans=all-1-nCa-nCb;
while(ans<0){
  ans+=MOD;
}
ans%=MOD;
cout<<ans<<endl;
}