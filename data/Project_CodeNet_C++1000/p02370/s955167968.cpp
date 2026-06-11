// BFSを用いたトポロジカルソート
// 計算量 O(V + E) 
// reference Programming Contest Challenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_4_B

#include <bits/stdc++.h>

using  ll = long long;
using ull = unsigned long long;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};
constexpr ll kINF = 1152921504606846976;//2^60
constexpr double kEPS = 1e-6;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define rep(i,n) REP(i,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep(i,n) RREP(i,n)
#define mp make_pair
#define fi first
#define sc second

// --!!!!ここからコピペする!!!!--

template<typename T> struct Edge {
  int to;
  Edge(int to_) : to(to_) {}
};

template<typename T,template <typename ELEM> class EDGE> struct AdListGraph {
  vector<vector<EDGE<T>>> G;

  vector<bool> used;
  vector<int> deg;
  int V;//0,...,|V|-1

  AdListGraph (int V_) {
    Init(V_);
  }

  void Init(int V_) {
    V = V_;

    G.clear();
    G.resize(V);
  }

  // https://faithandbrave.hateblo.jp/entry/20080310/1205149207
  template <typename FROM, class... Args>
  void AddEdge(FROM from, Args&&... arg) {
    G[from].emplace_back(arg...);
  }

  template<typename ID_TYPE>
  bool TopologicalSort (vector<ID_TYPE>& sorted) { // 成功ならtrue 失敗(DAG出ない)ならfalseを返す
    used.clear();
    used.resize(V, false);
    deg.clear();
    deg.resize(V, 0);
    sorted.clear();

    for (const auto& v : G) 
      for (const auto& e : v)
        deg[e.to]++;

    queue<int> que;

    rep (i, V) if (deg[i] == 0) {used[i] = true; que.push(i);}


    while(!que.empty()) {
      int i = que.front();
      que.pop();
      sorted.emplace_back(i);

      for (auto& e: G[i]) {
        deg[e.to]--;
        if (!used[e.to] && deg[e.to] == 0) {
          used[e.to] = true;
          que.push(e.to);
        }
      }
    }

    return !((int)sorted.size() == V);
  }

};

using ll = long long;

int main() {
  ll V,E;
  cin >> V >> E;
  AdListGraph<ll, Edge> G(V);
  rep(i,E) {
    ll s,t;
    cin >> s >> t;
    G.AddEdge(s,t);
  }

  vector<int> ans;

  G.TopologicalSort(ans);

  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}

