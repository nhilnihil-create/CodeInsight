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
      std::vector<Weight> dist(g.size(), INF);
      dist[src] = 0;
      q.emplace(0, src);
      while (q.size()) {
        Weight d;
        int v;
        std::tie(d, v) = q.top();
        q.pop();
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
          if (dist[e.dst] > dist[v] + e.weight) {
            dist[e.dst] = dist[v] + e.weight;
            q.emplace(dist[e.dst], e.dst);
          }
        }
      }
      return dist;
    }
  };
}
using namespace libgraph;

main {
  int v, e, r;
  cin >> v >> e >> r;
  Graph g(v);
  while (e--) {
    int s, t, d;
    cin >> s >> t >> d;
    g.addArc(s, t, d);
  }
  vector<Weight> dist = g.dijkstra(r, INF);
  rep(i, dist.size()) cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
}