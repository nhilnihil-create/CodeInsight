#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
using namespace atcoder;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Q; cin >> N >> Q;
  dsu d(N);
  REP(i, Q){
    int t, u, v; cin >> t >> u >> v;
    if(t == 0){
      d.merge(u, v);
    }else{
      if(d.same(u, v)){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
    }
  }
}