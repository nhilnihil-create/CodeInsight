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
  fenwick_tree<ll> A(N);
  rep(i,N){
    ll a;
    cin >> a;
    A.add(i,a);
  }
  rep(i,Q){
    ll a,b,c;
    cin >> a >> b >> c;
    if(a==0){
      A.add(b,c);
    }else{
      cout << A.sum(b,c) << endl;
    }
  }
}