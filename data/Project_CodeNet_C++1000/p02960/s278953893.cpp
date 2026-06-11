#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

ll modPow(ll a, ll n,ll p) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1,p)) % p;
  ll t = modPow(a, n / 2,p);
  return (t * t) % MOD;
}

int main(){
  string S;
  cin >> S;
  vector<vector<ll>> dp((ll)S.size(),vector<ll>(13,0));
  rep(i,(ll)S.size()){
    if(i==0){
      if(S.at(i)=='?'){
        rep(j,10){
          dp.at(i).at(j)=1;
        }
      }else{
        dp.at(i).at(S.at(i)-'0')=1;
      }
    }else{
      rep(j,13){
        if(S.at(i)=='?'){
          rep(k,10){
            dp.at(i).at((k+10*j)%13)+=dp.at(i-1).at(j);
            dp.at(i).at((k+10*j)%13)%=MOD;
          }
        }else{
          dp.at(i).at((S.at(i)-'0'+10*j)%13)+=dp.at(i-1).at(j);
          dp.at(i).at((S.at(i)-'0'+10*j)%13)%=MOD;
        }
      }
    }
  }
  cout << dp.at((ll)S.size()-1).at(5) << endl;
  
}