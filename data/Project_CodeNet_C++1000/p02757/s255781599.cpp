#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000;
#define all(v) v.begin(), v.end()

ll M;
ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % M;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % M;
  ll t = modPow(a, n / 2);
  return (t * t) % M;
}

int main(){
  ll N,ans=0;
  string S;
  cin >> N >> M >> S;
  vector<ll> T(N+1),U(M,0);
  if(M==2){
    rep(i,N){
      if(S.at(i)=='0'||S.at(i)=='2'||S.at(i)=='4'||S.at(i)=='6'||S.at(i)=='8'){
        ans+=i+1;
      }
    }
    cout << ans << endl;
  }else if(M==5){
    rep(i,N){
      if(S.at(i)=='0'||S.at(i)=='5'){
        ans+=i+1;
      }
    }
    cout << ans << endl;
  }else{
    T.at(0)=0;
    U.at(0)++;
    rep(i,N){
      T.at(i+1)=T.at(i)+(S.at(N-i-1)-'0')*modPow(10,i);
      T.at(i+1)%=M;
      U.at(T.at(i+1))++;
    }
    rep(i,M){
      ans+=(U.at(i)*(U.at(i)-1))/2;
    }
    cout << ans << endl;
  }
}