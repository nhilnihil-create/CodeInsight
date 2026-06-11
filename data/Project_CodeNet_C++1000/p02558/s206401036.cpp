#include<iostream>
#include<vector>
using namespace std;

class DisjointSetUnion {
  int size;
  vector<int> V;
  public:
  DisjointSetUnion(int s): size(s), V(s, -1) {
    for (int i = 0; i < s; i++) V[i] = i;
  }
  void connect(int u, int v) {
    V[find(u)] = find(v);
  }
  int find(int node) {
    int cur_node = node, p = V[node];
    while (cur_node != p) {
      V[cur_node] = V[p];
      cur_node = p;
      p = V[p];
    }
    return cur_node;
  }
  int same(int u, int v) {
    return (find(u) == find(v));
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;
  int t, u, v;
  DisjointSetUnion d(N);
  for (int q = 0; q < Q; q++) {
    cin >> t >> u >> v;
    if (t == 0) {
      d.connect(u, v);
    } else {
      cout << d.same(u, v) << endl;
    }
  }
}