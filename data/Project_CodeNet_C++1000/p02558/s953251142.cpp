#include <bits/stdc++.h>
using namespace std;

#pragma region lib_unionfind_tree
namespace lib {
  /*
    class UnionFind
    usage: Unionfind u(100), u.unite(1, 10), u.find(1, 13)
  */
  class UnionFind {
    public:
    UnionFind() {}
    UnionFind(int n) :
        parent(n, -1), rank(n, 0) {}

    int find(int a) {
      if (parent[a] == -1)
        return a;
      else
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
      a = find(a);
      b = find(b);

      if (a == b) return;
      if (rank[a] == rank[b]) {
        parent[a] = b;
        rank[b]++;
        return;
      }
      if (rank[a] > rank[b]) swap(a, b);
      parent[a] = b;
    }

    private:
    vector<int> parent, rank;
  };
}  // namespace lib
#pragma endregion

int main() {
  int N, Q;
  cin >> N >> Q;

  lib::UnionFind uf(N);

  while (Q--) {
    int t, u, v;
    cin >> t >> u >> v;

    if (t == 0)
      uf.unite(u, v);
    else
      cout << (uf.find(u) == uf.find(v)) << endl;
  }

  return 0;
}
