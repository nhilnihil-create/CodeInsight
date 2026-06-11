#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD =1000000007;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}
ll modComb(ll n,ll a){
  ll x=1,y=1;
  rep(i,a){
    x*=n-i;
    x%=MOD;
    y*=i+1;
    y%=MOD;
  }
  y=modPow(y,MOD-2);
  return (x*y)%MOD;
}

int main(){
  ll N,ans=0;
  cin >> N;
  vector<ll> A(N),Pow(61);
  vector<P> B(60,P(0,0));
  rep(j,61){
    Pow.at(j)=(ll)pow(2,j);
  }
  rep(i,N){
    cin >> A.at(i);
    rep(j,60){
      if(A.at(i)%Pow.at(j+1)>A.at(i)%Pow.at(j)){
        B.at(j).first++;
      }else{
        B.at(j).second++;
      }
    }
  }
  rep(j,60){
    ans+=((B.at(j).first*B.at(j).second)%MOD)*modPow(2,j);
    ans%=MOD;
  }
  cout << ans << endl;
  
  
  
  
  
  
}