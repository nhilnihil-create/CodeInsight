#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll MOD = 1000000007;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}


int main(){
  ll N,M,j=0;
  cin >> N >> M;
  vector<ll> A(M),ans(N+1);
  for(ll i=0;i<M;i++) cin >> A.at(i);
  ans.at(0)=1;
  if(M==0){
    ans.at(1)=1;
  }else{
    if(A.at(0)==1){
      ans.at(1)=0;
      j++;
    }else{
      ans.at(1)=1;
    }
  }
  for(ll i=2;i<=N;i++){
    if(j<M){
      if(i==A.at(j)){
        ans.at(i)=0;
        j++;
      }else{
        ans.at(i)=ans.at(i-1)+ans.at(i-2);
        ans.at(i)%=MOD;
      }
    }else{
      ans.at(i)=ans.at(i-1)+ans.at(i-2);
      ans.at(i)%=MOD;
    }
  }
  cout << ans.at(N) << endl;
 
      
}