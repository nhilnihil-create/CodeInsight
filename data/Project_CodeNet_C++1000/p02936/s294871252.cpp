#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> g[200009];
vector<int> cnt(200009, 0);
vector<bool> visited(200009, false);

void dfs(int pos) {
  rep(i, g[pos].size()) {
    int to = g[pos][i];
    if (visited[to]) continue;;
    visited[to] = true;
    cnt[to] += cnt[pos];
    // printf("cnt[%d] = %d, cnt[%d] = %d\n", pos, cnt[pos], to, cnt[to]);
    dfs(to);
  }
  return;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n-1), b(n-1), p(q), x(q);
  rep(i, n-1) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }
  rep(i, q) {
    cin >> p[i] >> x[i];
    --p[i];
  }

  rep(i, n-1) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  
  rep(i, q) cnt[p[i]] += x[i];

  visited[0] = true;
  dfs(0);

  rep(i, n-1) printf("%d ", cnt[i]);
  printf("%d\n", cnt[n-1]);

  return 0;
}