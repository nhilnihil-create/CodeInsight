#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

using Graph = vector<vector<int>>;
int main(){
  int N, M; cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; ++i){
    int u, v; cin >> u >> v; --u, --v;
    G[u].push_back(v);
  }
  int S, T; cin >> S >> T;
  --S, --T;

  //-----------------//
  // pair<node, mod3>
  vector<vector<ll>> dist(N, vector<ll>(3, -1));
  dist[S][0] = 0;
  queue<P> que;
  que.push({S, 0});
  while (!que.empty()){
    P cur = que.front(); que.pop();
    int v = cur.first;
    int parity = cur.second;
    for (auto nv : G[v]){
      int np = (parity + 1) % 3;
      if (dist[nv][np] == -1){
        dist[nv][np] = dist[v][parity] + 1;
        que.push({nv, np});
      }
    }
  }
  if (dist[T][0] == -1) cout << -1 << endl;
  else cout << dist[T][0] / 3 << endl;
}
