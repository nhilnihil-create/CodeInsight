#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

static const int MAX = 10000;
static const int INFTY = (1 << 29);

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  V[s] = true;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    out.push_back(u);
    rep(i, 0, G[u].size()) {
      int v = G[u][i];
      indeg[v]--;
      if (indeg[v] == 0 && !V[v]) {
        V[v] = true;
        q.push(v);
      }
    }
  }
};

void tsort() {
  rep(i, 0, N)  {
    indeg[i] = 0;
  }

  rep(u, 0, N)  {
    rep(i, 0, G[u].size()) {
      int v = G[u][i];
      indeg[v]++;
    }
  }

  rep(u, 0, N)  {
    if (indeg[u] == 0 && !V[u]) bfs(u);
  }

  for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
    cout << *it << endl;
  }
};

int main() {
  int s, t, M;
  cin >> N >> M;

  rep(i, 0, N) {
    V[i] = false;
  }

  rep(i, 0, M) {
    cin >> s >> t;
    G[s].push_back(t);
  }

  tsort();
};

