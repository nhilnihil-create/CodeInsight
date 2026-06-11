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
  using iterator = std::vector<Edges>::iterator;
  using const_iterator = std::vector<Edges>::const_iterator;

public:
  Graph(const int &size = 0) : g(size) {}
  int size() const { return g.size(); }
  const Edges &operator[](const int &i) const { return g[i]; }
  void addArc(const int &src, const int &dst, const Weight &w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  iterator begin() { return g.begin(); }
  const_iterator begin() const { return g.begin(); }
  iterator end() { return g.end(); }
  const_iterator end() const { return g.end(); }
};

template<int inf = std::numeric_limits<Weight>::max() / 8> std::pair<std::vector<Weight>, bool> bellmanFord(const Graph &g, int src) {
  int n = g.size();
  Edges es;
  for (auto &adj : g) {
    for (auto &e : adj) es.emplace_back(e);
  }
  std::vector<Weight> dist(n, inf);
  dist[src] = 0;
  bool negCycle = false;
  for (int i = 0;; i++) {
    bool updated = false;
    for (auto &e : es) {
      if (dist[e.src] != inf) {
        if (cmin(dist[e.dst], dist[e.src] + e.weight)) updated = true;
      }
    }
    if (!updated) break;
    if (i > n) {
      negCycle = true;
      break;
    }
  }
  return {dist, negCycle};
}

main {
  int v, e, r;
  cin >> v >> e >> r;
  Graph g(v);
  while (e--) {
    int s, t, d;
    cin >> s >> t >> d;
    g.addArc(s, t, d);
  }
  V<Weight> dist;
  bool negCycle;
  tie(dist, negCycle) = bellmanFord<INF>(g, r);
  if (negCycle) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for (auto &x : dist) cout << (x == INF ? "INF" : to_string(x)) << endl;
}