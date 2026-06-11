#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100000;
const int MOD = 1e9 + 7;

int n, k;
vector<int> G[N];

bool visited[N], painted[N];

void dfs(int v, int *p) {
  visited[v] = true;
  int c = 0;
  int kk = k;
  if (painted[v]) {
    kk--;
  } else {
    c++;
    painted[v] = true;
  }
  rep(i, G[v].size()) {
    int to = G[v][i];
    if (painted[to]) {
      kk--;
    } else {
      c++;
      painted[to] = true;
    }
  }
  rep(i, c) *p = (ll)*p * (kk--) % MOD;

  rep(i, G[v].size()) {
    int to = G[v][i];
    if (visited[to]) continue;
    dfs(to, p);
  }
  // printf("v = %d, *p = %d\n", v, *p);
}

int main() {
  cin >> n >> k;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, n) visited[i] = false;
  rep(i, n) painted[i] = false;
  int ans = 1;
  dfs(0, &ans);
  cout << ans << endl;
  return 0;
}