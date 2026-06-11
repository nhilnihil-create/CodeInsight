#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a= b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a= b;
    return 1;
  }
  return 0;
}
ll mod= 998244353;

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M)%M;
}

int main() {
  ll ans= 1;
  ll n;
  cin >> n;
  ll a[n]= {};
  ll b[n];
  ll ma=0;
  rep(i, n) {
    cin >> b[i];
    a[b[i]]++;
    chmax(ma,b[i]);
  }
  rep(i,ma+1)if(a[i]==0){cout<< 0 << endl; return 0;}//一番近い頂点同士との距離が2以上は存在してはいけない
  if(a[0]!=1){cout << 0 <<endl;return 0;}//頂点1との距離0は1個でないといけない
  if(b[0]!=0){cout << 0 <<endl;return 0;}//頂点1が0でないといけない
  
  for(int i=1;i<=ma;i++){
      ans=ans*RepeatSquaring(a[i-1],a[i],mod)%mod;
  }
  cout << ans << endl;
}