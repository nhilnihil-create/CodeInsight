#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

int main(){
  ll N;
  cin >> N;
  vec X(N);
  rep(i,N){
    cin >> X.at(i);
  }
  ll ans=INF;
  rep(i,100){
    ll k=0;
    rep(j,N){
      k+=(X.at(j)-i-1)*(X.at(j)-i-1);
    }
    ans=min(k,ans);
  }
  cout << ans << endl;
}
    