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

template<typename InputIterator> constexpr std::string join(InputIterator first, InputIterator last, const std::string &sep) {
  if (first == last) return "";
  std::stringstream ss;
  ss << *(first++);
  for_each(first, last, [&](auto &x) { ss << sep << x; });
  return ss.str();
}

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

main {
  int n;
  cin >> n;
  Graph g(n);
  rep(_, n) {
    int u, k;
    cin >> u >> k;
    while (k--) {
      int v;
      cin >> v;
      g.addArc(u - 1, v - 1);
    }
  }
  Matrix d(n, Array(n, 0));
  rep(i, n) for (auto &e : g[i]) d[e.src][e.dst] = 1;
  for (auto &r : d) cout << join(all(r), " ") << endl;
}