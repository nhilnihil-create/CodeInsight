// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever while (true)
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
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for (T &x : v) is >> x; return is; }
using namespace std;
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int &s = 0, const int &d = 0, const Weight &w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = std::vector<Edge>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

class Graph {
  std::vector<Edges> g;

public:
  Graph(const int &size = 0) : g(size) {}

  void addArc(const int &src, const int &dst, const Weight &w = 1) { g[src].emplace_back(src, dst, w); }

  void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }

  const Edges &operator[](const int &i) const { return g[i]; }

  Graph toRootedTree(int r);
  std::pair<std::vector<Weight>, std::vector<int>> dijkstra(const int &src, const int &inf);
  Matrix warshallFloyd(const int &inf);
  std::pair<Weight, Edges> prim(const int &r);
  template<typename UnionFind> std::pair<Weight, Edges> kruskal();
  Weight solveTSP(const int &inf);
};

std::pair<Weight, Edges> Graph::prim(const int &r = 0) {
  struct comp {
    bool operator()(const Edge &e, const Edge &f) const { return e.weight > f.weight; }
  };
  Edges tree;
  Weight total = 0;
  std::vector<int> vs(g.size());
  std::priority_queue<Edge, std::vector<Edge>, comp> q;
  q.emplace(-1, r, 0);
  while (q.size()) {
    Edge e = q.top();
    q.pop();
    if (vs[e.dst]) continue;
    vs[e.dst] = true;
    total += e.weight;
    if (e.src != -1) tree.emplace_back(e);
    for (auto &f : g[e.dst]) {
      if (!vs[f.dst]) q.emplace(f);
    }
  }
  return {total, tree};
}

main {
  int n;
  cin >> n;
  Graph g(n);
  rep(i, n) rep(j, n) {
    int a;
    cin >> a;
    if (a >= 0) g.addArc(i, j, a);
  }
  cout << g.prim().first << endl;
}