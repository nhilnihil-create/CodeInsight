#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll MOD = 2019;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}


int main(){
  string S;
  cin >> S;
  vector<ll> T(S.size());
  T.at(0)=(S.at(S.size()-1)-'0');
  for(ll i=1;i<S.size();i++){
    T.at(i)=T.at(i-1)+(S.at(S.size()-i-1)-'0')*modPow(10,i);
    T.at(i)%=MOD;
  }
  sort(T.begin(),T.end());
  ll t=0,x=1,ans=0;
  for(ll i=0;i<S.size();i++){
    if(t==T.at(i)){
      x++;
    }else{
      ans+=(x*(x-1))/2;
      x=1;
      t=T.at(i);
    }
  }
  ans+=(x*(x-1))/2;
  cout << ans << endl;
      
}