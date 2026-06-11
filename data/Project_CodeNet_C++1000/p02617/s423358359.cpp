#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // Treeなので連結成分は、頂点数 - 辺の数
  int N;
  cin >> N;
  ll ans = 0;
  for (ll i = 1; i < N+1; i++) {
    ans += i * (N-i+1);
  }
  vector<int> graph[N+1]; // 1-indexed
  rep(i, N-1) {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    ans -= a * (N-b+1);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cout << ans << '\n';
  return 0;
}