#include <bits/stdc++.h>
using namespace std;

const int64_t MOD=998244353;

int64_t modpow(int64_t a,int64_t n){
  int64_t res=1;
  if(n==0) return res;
  while(n>0){
    if(n&1) res=(res*a)%MOD;
    a=(a*a)%MOD;
    n >>= 1;
  }
  return res;
}


int main(){
  int N;
  cin>>N;
  vector<int64_t> D(N);
  for(int i=0;i<N;++i) cin>>D[i];
  int64_t ans=0;

  if(D[0]!=0) cout<<0<<endl;
  else{
    ans=1;
    map<int,int> S;
    for(int i=0;i<N;++i){
      ++S[D[i]];
    }
    if(S[0]>1) cout<<0<<endl;
    else{
      for(auto p:S){
        if(p.first>0){
        ans *= modpow(S[p.first-1],S[p.first]);
        ans %= MOD;
        }
      }
      cout<<ans<<endl;
    }
  }
}