#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005;
vector<P> G[N];
int clr[N];
vector<bool> visited(N, false);
int k = 0;

void dfs(int pos, int c) {
  visited[pos] = true;
  int cnt = 0;
  rep(i, G[pos].size()) {
    P p = G[pos][i];
    int to = p.first;
    if (visited[to]) continue;
    clr[p.second] = (c + (cnt++)) % k + 1;
    dfs(to, clr[p.second]);
  }
  return;
}

int main() {
  int n;
  cin >> n;
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(make_pair(b, i));
    G[b].push_back(make_pair(a, i));
  }

  rep(i, n) k = max(k, (int)G[i].size());
  cout << k << endl;

  dfs(0, 0);
  rep(i, n-1) cout << clr[i] << endl;
  return 0;
}