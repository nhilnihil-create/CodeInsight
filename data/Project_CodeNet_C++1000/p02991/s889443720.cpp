#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;

vector<int> dijkstra(int i, int n, vector<vector<pair<int, int>>> graph) {
  vector<int> d(n, INF);
  d[i] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push(make_pair(0, i));
  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    int v = p.second;
    if (d[v] < p.first) {
      continue;
    }
    for (auto x : graph[v]) {
      if (d[x.first] > d[v] + x.second) {
        d[x.first] = d[v] + x.second;
        q.push(pair<int, int>(d[x.first], x.first));
      }
    }
  }
  return d;
}

signed main() {
  int N, M; 
  cin >> N >> M;

  vector<vector<pair<int, int>>> graph(3*N);
  REP(i, M){
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v+N, 1);
    graph[u+N].emplace_back(v+2*N, 1);
    graph[u+2*N].emplace_back(v, 1);
  }

  int s, t;
  cin >> s >> t;
  s--; t--;

  vector<int> dist = dijkstra(s, 3*N, graph);
  if(dist[t] == INF) dist[t] = -3;

  cout << dist[t]/3 << endl;

  return 0;
}