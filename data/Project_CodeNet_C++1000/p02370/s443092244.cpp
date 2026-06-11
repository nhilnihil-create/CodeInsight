// DFSを用いたトポロジカルソート
// 計算量 O(V + E) 
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

template<typename T,template <typename ELEM> class C> struct AdListGraph {
  vector<vector<C<T>>> G;
  vector<bool> used;
  vector<bool> is_ancetor;
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

  bool DFSForTopologicalSort (int i, vector<int>& sorted) {
    if (is_ancetor[i]) return false;
    if (used[i]) return true;

    used[i] = true;
    is_ancetor[i] = true;

    for(const auto& v : G[i]) {
      if(!DFSForTopologicalSort(v.to, sorted)) return false;
    }

    is_ancetor[i] = false;
    sorted.emplace_back(i);//dfsの帰りがけの順

    return true;
  }

  template<typename ID_TYPE>
  bool TopologicalSort (vector<ID_TYPE>& sorted) { // 成功ならtrue 失敗(DAG出ない)ならfalseを返す
    used.clear();
    used.resize(V,false);
    is_ancetor.clear();
    is_ancetor.resize(V, false);

    sorted.clear();

    rep (i,V) {
      if(!DFSForTopologicalSort(i, sorted)) {
        return false;
      }
    }

    reverse(sorted.begin(),sorted.end());

    return true;
  }

};

using ll = long long;

int main() {
  ll V,E;
  cin >> V >> E;
  AdListGraph<ll,edge> G(V);
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

