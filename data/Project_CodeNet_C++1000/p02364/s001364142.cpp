// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int &n) { return n & 1; }
constexpr bool even(const int &n) { return !odd(n); }
// clang-format on

namespace libgraph {
  using Weight = int;
  struct Edge {
    int src, dst;
    Weight weight;
    Edge(const int &s = 0, const int &d = 0, const Weight &w = 0)
      : src(s), dst(d), weight(w) {
    }
  };

  using Edges  = std::vector<Edge>;
  using Array  = std::vector<Weight>;
  using Matrix = std::vector<Array>;

  class Graph {
    std::vector<Edges> g;

  public:
    Graph(const int &size = 0)
      : g(size) {
    }

    void addArc(const int &src, const int &dst, const Weight &w = 1) {
      g[src].emplace_back(src, dst, w);
    }

    void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
      addArc(node1, node2, w);
      addArc(node2, node1, w);
    }

    std::vector<Weight> dijkstra(const int &src, const int &inf = std::numeric_limits<Weight>::max() / 8) {
      using state = std::pair<Weight, int>;
      std::priority_queue<state, std::vector<state>, std::greater<state>> q;
      std::vector<Weight> dist(g.size(), inf);
      dist[src] = 0;
      q.emplace(0, src);
      while (q.size()) {
        Weight d;
        int v;
        std::tie(d, v) = q.top();
        q.pop();
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
          if (cmin(dist[e.dst], dist[v] + e.weight)) {
            q.emplace(dist[e.dst], e.dst);
          }
        }
      }
      return dist;
    }

    Matrix warshallFloyd(const int &inf = std::numeric_limits<Weight>::max() / 8) {
      int n = g.size();
      Matrix d(n, Array(n, inf));
      rep(i, n) d[i][i] = 0;
      rep(i, n) for (auto &e : g[i]) cmin(d[e.src][e.dst], e.weight);
      rep(k, n) rep(i, n) rep(j, n) {
        if (d[i][k] != inf && d[k][j] != inf) cmin(d[i][j], d[i][k] + d[k][j]);
      }
      return d;
    }

    std::pair<Weight, Edges> prim(const int &r = 0) {
      struct comp {
        bool operator()(const Edge &e, const Edge &f) const {
          return e.weight > f.weight;
        }
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
      return std::make_pair(total, tree);
    }

    template<typename UnionFind>
    std::pair<Weight, Edges> kruskal() {
      UnionFind uf(g.size());
      Edges es;
      for (auto &adj : g) {
        for (auto &e : adj) es.emplace_back(e);
      }
      std::sort(es.begin(), es.end(), [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
      Weight total = 0;
      Edges tree;
      for (auto &e : es) {
        if (!uf.same(e.src, e.dst)) {
          tree.pb(e);
          total += e.weight;
          uf.unite(e.src, e.dst);
        }
      }
      return std::make_pair(total, tree);
    }
  };
}
using namespace libgraph;

class UFT {
private:
  vi data, rnk, _size;

public:
  UFT(const int &n)
    : data(n), rnk(n), _size(n, 1) {
    iota(all(data), 0);
  }

  int root(const int &x) {
    return data[x] == x ? x : data[x] = root(data[x]);
  }

  bool same(const int &a, const int &b) {
    return root(a) == root(b);
  }

  void unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    data[b] = a;
    _size[a] += _size[b];
    if (rnk[a] == rnk[b]) rnk[a]++;
  }

  int size(int x) {
    return _size[root(x)];
  }
};

main {
  int v, e;
  cin >> v >> e;
  Graph g(v);
  while (e--) {
    int s, t, w;
    cin >> s >> t >> w;
    g.addEdge(s, t, w);
  }
  cout << g.kruskal<UFT>().fi << endl;
}