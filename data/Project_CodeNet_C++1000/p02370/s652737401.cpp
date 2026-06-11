// DP F

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFL = 1LL<<60;

void dump(const vector<pair<int, int>>& a)
{
  for (auto v : a) {
    cerr << v.first << " " << v.second << endl;
  }
}

////////////////////////////////////////////////////

static const int MAX = 100000;
bool V[MAX];
list<int> out;
vector<int> G[MAX];
int N;
int indeg[MAX];

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  V[s] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    out.push_back(u);
    rep(i, G[u].size()) {
      int v = G[u][i];
      indeg[v]--;
      if (indeg[v] == 0 && !V[v]) {
        V[v] = true;
        q.push(v);
      }
    }
  }
}

void topologicalSort()
{
  rep(i, N) {
    indeg[i] = 0;
  }

  rep(u, N) {
    rep(i, G[u].size()) {
      int v = G[u][i];
      indeg[v]++;
    }
  }

  rep(u, N) {
    if (indeg[u] == 0 && !V[u]) {
      bfs(u);
    }
  }

  for (auto it = out.begin(); it != out.end(); it++) {
    cout << *it << endl;
  }
}

int main()
{
  int s, t, M;
  cin >> N >> M;
  rep(i, N) {
    V[i] = false;
  }
  rep(i, M) {
    cin >> s >> t;
    G[s].push_back(t);
  }
  topologicalSort();
  return 0;
}

