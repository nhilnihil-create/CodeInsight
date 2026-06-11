#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> graph[200005];
vector<ll> cnt;

void dfs(int c, int p=-1) {
  for (int ne : graph[c]) {
    if (ne == p) continue;
    cnt[ne] += cnt[c];
    dfs(ne, c);
  }
}

int main() {
  int n, q;
  cin >> n >> q;  
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cnt.resize(n+1);
  rep(i, q) {
    int p, q;
    cin >> p >> q;
    cnt[p] += q;    
  }
  dfs(1);
  for (int i = 1; i < n+1; i++) {
    cout << cnt[i] << ' ';
  }
  return 0;
}