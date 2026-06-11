#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD =998244353
 ;

int main(){
  ll N,S;
  cin >> N >> S;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  vector<vector<ll>> dp(N,vector<ll>(S+1,0));
  dp.at(0).at(0)=2;
  if(A.at(0)<=S){
    dp.at(0).at(A.at(0))=1;
  }
  for(ll i=1;i<N;i++){
    for(ll j=0;j<=S;j++){
      dp.at(i).at(j)+=dp.at(i-1).at(j)*2;
      dp.at(i).at(j)%=MOD;
      if(j+A.at(i)<=S){
        dp.at(i).at(j+A.at(i))+=dp.at(i-1).at(j);
        dp.at(i).at(j+A.at(i))%=MOD;
      }
    }
  }
  cout <<dp.at(N-1).at(S) << endl;
        
  
  
}
