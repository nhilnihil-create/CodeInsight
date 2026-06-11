// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever for (;;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
template<typename A> using V = std::vector<A>;
template<typename A> using F = std::function<A>;
template<typename A, typename B> using P = std::pair<A, B>;
using pii = P<int, int>;
using vi = V<int>;
using vd = V<double>;
using vs = V<std::string>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvpii = V<vpii>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int n) { return n & 1; }
constexpr bool even(const int n) { return ~n & 1; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
using namespace std;
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int s = 0, const int d = 0, const Weight w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = std::vector<Edge>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

class Graph {
  std::vector<Edges> g;
  using iterator = std::vector<Edges>::iterator;
  using const_iterator = std::vector<Edges>::const_iterator;

public:
  Graph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int i) const { return g[i]; }
  void addArc(const int src, const int dst, const Weight w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int node1, const int node2, const Weight w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  iterator begin() { return g.begin(); }
  const_iterator begin() const { return g.begin(); }
  iterator end() { return g.end(); }
  const_iterator end() const { return g.end(); }
};

class UFTree {
  std::vector<int> tree, rank, _size;

public:
  UFTree(const int n) : tree(n), rank(n), _size(n, 1) { iota(all(tree), 0); }

  int root(const int x) { return tree[x] == x ? x : tree[x] = root(tree[x]); }

  bool same(const int a, const int b) { return root(a) == root(b); }

  bool unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return false;
    if (rank[a] < rank[b]) std::swap(a, b);
    tree[b] = a;
    _size[a] += _size[b];
    if (rank[a] == rank[b]) rank[a]++;
    return true;
  }

  int sizeOf(int x) { return _size[root(x)]; }

  int size() { return tree.size(); }
};

template<typename UnionFind> std::pair<Weight, Edges> kruskal(const Graph &g) {
  UnionFind uf(g.size());
  Edges es;
  for (auto &adj : g) {
    for (auto &e : adj) es.emplace_back(e);
  }
  std::sort(es.begin(), es.end(), [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
  Weight total = 0;
  Edges tree;
  for (auto &e : es) {
    if (uf.unite(e.src, e.dst)) tree.push_back(e), total += e.weight;
  }
  return {total, tree};
}

main {
  int v, e;
  cin >> v >> e;
  Graph g(v);
  while (e--) {
    int s, t, w;
    cin >> s >> t >> w;
    g.addEdge(s, t, w);
  }
  cout << kruskal<UFTree>(g).first << endl;
}