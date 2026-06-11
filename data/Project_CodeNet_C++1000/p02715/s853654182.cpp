#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}
vector<ll> Prime(10000,0);
void sosu(ll n){
  Prime.at(0)=2;
  ll t=1;
  for(ll i=3;i<n;i++){
    rep(j,t){
      if(i%Prime.at(j)==0){
        break;
      }
      if(j==t-1){
        Prime.at(t)=i;
        t++;
        
      }
    }
  }
}
    

int main(){
  ll N,K,M=0;
  cin >> N >> K;
  vector<ll> ans(K,0);
  sosu(N);
  for(ll i=K;i>0;i--){
    ans.at(i-1)=modPow(K/i,N);
    ll t=2;
    while(i*t<=K){
      ans.at(i-1)+=MOD;
      ans.at(i-1)-=ans.at(i*t-1);
      ans.at(i-1)%=MOD;
      t++;
    }
  }
  rep(i,K){
    M+=(i+1)*ans.at(i);
    M%=MOD;
  }
  cout << M << endl;
                     
                     
    
 
      
}
