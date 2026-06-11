// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
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
void solve();
main { solve(); return 0; }
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int s = 0, int d = 0, Weight w = 0)
    : src(s), dst(d), weight(w) {
  }
};

using Edges  = vector<Edge>;
using Graph  = vector<Edges>;
using Array  = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, const int &a, const int &b, const Weight &w = 1) {
  g[a].emplace_back(a, b, w);
}

void addEdge(Graph &g, const int &a, const int &b, const Weight &w = 1) {
  addArc(g, a, b, w);
  addArc(g, b, a, w);
}

// deps: graph-basic
bool operator<(const Edge &e, const Edge &f) {
  return e.weight > f.weight;
}

pair<Weight, Edges> prim(const Graph &g, const int &r = 0) {
  Edges T;
  Weight total = 0;
  vi vs(g.size());
  priority_queue<Edge> q;
  q.emplace(-1, r, 0);
  while (q.size()) {
    Edge e = q.top();
    q.pop();
    if (vs[e.dst]) continue;
    vs[e.dst] = true;
    total += e.weight;
    if (e.src != -1) T.emplace_back(e);
    for (auto &f : g[e.dst]) {
      if (!vs[f.dst]) q.emplace(f);
    }
  }
  return mp(total, T);
}

void solve() {
  int v, e;
  cin >> v >> e;
  Graph g(v);
  while (e--) {
    int s, t, w;
    cin >> s >> t >> w;
    addEdge(g, s, t, w);
  }
  cout << prim(g).first << endl;
}