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

vector<Weight> dijkstra(const Graph &g, const int &s) {
  using state = tuple<Weight, int>;
  priority_queue<state, vector<state>, greater<state>> q;
  vector<Weight> dist(g.size(), INF);
  dist[s] = 0;
  q.emplace(0, s);
  while (q.size()) {
    Weight d;
    int v;
    tie(d, v) = q.top();
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

void solve() {
  int v, e, r;
  cin >> v >> e >> r;
  Graph g(v);
  while (e--) {
    int s, t, d;
    cin >> s >> t >> d;
    addArc(g, s, t, d);
  }
  vector<Weight> dist = dijkstra(g, r);
  rep(i, dist.size()) cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
}