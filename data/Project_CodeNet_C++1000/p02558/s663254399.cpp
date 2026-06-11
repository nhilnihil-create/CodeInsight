#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (long long i = 0; i < (n); ++i)
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
  ll N,Q;
  cin >> N >> Q;
  dsu A(N);
  rep(i,Q){
    ll t,a,b;
    cin >> t >> a >> b;
    if(t==0){
      A.merge(a,b);
    }else{
      if(A.same(a,b)){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
    }
  }
}