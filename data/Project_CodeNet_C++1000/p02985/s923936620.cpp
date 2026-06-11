#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

#define MAX 200000
#define MOD 1000000007

long long modpow(long long a,long long n,long long mod){
  long long res=1;
  while(n>0){
    if(n&1){       //nのbitと...00001を比較  nが2で割り切れるならtrue
      res=(res*a)%mod;
    }
    a=(a*a)%mod;
    n>>=1;
  }
  return res;
}

long long modinv(long long a,long long mod){
  return modpow(a,mod-2,mod);
}

long long fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=(fac[i-1]*i)%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

long long COM(int n,int k){
  if(n<k){
    return 0;
  }
  if(n<0||k<0){
    return 0;
  }
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

Graph G;
ll K;

int solve(int v,int p){
  int n=G.at(v).size();
  if(K-1<n){
    return 0;
  }
  ll ans=fac[K-2]*finv[K-2-n+1]%MOD;
  if(v==0){
    ans=fac[K]*finv[K-n-1]%MOD;
  }
  for(auto nv:G.at(v)){
    if(nv==p){
      continue;
    }
    ans*=solve(nv,v);
    ans%=MOD;
  }
  return ans;
}

int main(){
  int N;
  cin>>N>>K;
  G.resize(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  COMinit();

  cout<<solve(0,-1)<<endl;
}
