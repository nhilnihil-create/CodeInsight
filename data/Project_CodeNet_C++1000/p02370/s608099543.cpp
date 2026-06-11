// DFSを用いたトポロジカルソート
// 計算量 O(V) 
// reference Programming Contest Challenge Book Second Edition
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_4_B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

template<typename T> struct edge {
  int to;
  edge(int to_) : to(to_) {}
};

template<typename T,template <typename ELEM> class C> struct Topological_Sort {
  vector<vector<C<T>>> G;
  vector<bool> used;
  int V;//0,...,|V|-1
  T INF;

  Topological_Sort (int V_) {
    init(V_);
  }

  void init(int V_) {
    V = V_;

    G.clear();
    G.resize(V);
  }

  // https://faithandbrave.hateblo.jp/entry/20080310/1205149207
  template <typename FROM, class... Args>
  void add_edge(FROM from, Args&&... arg) {
    G[from].emplace_back(arg...);
  }

  void dfs (int i, vector<int> &sorted) {
    used[i] = true;

    rep(j,(int)G[i].size()) {
      if (!used[G[i][j].to]) {
        dfs(G[i][j].to, sorted);
      }
    }

    sorted.emplace_back(i);//dfsの帰りがけの順
  }

  template<typename ID_TYPE>
  bool topological_sort (vector<ID_TYPE> &sorted) { // 成功ならtrue 失敗(DAG出ない)ならfalseを返す
    used.clear();
    used.resize(V,false);

    sorted.clear();

    rep (i,V) {
      if (!used[i]) dfs(i,sorted);
    }

    // DAGでないときトポロジカルソート出来ないのでfalseを返す
    // https://ferin-tech.hatenablog.com/entry/2017/01/24/184750
    if (V != (int)(sorted.size())) return false;

    reverse(sorted.begin(),sorted.end());

    return true;
  }

};

using ll = long long;

int main() {
  ll V,E;
  cin >> V >> E;
  Topological_Sort<ll,edge> ts(V);
  rep(i,E) {
    ll s,t;
    cin >> s >> t;
    ts.add_edge(s,t);
  }

  vector<int> ans;

  ts.topological_sort(ans);

  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}

