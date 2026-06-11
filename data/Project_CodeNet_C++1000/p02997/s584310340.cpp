#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  if (K > (N-1) * (N-2) / 2) {
    cout << -1 << '\n';
    return 0;
  }
  vector<P> edges;
  for (int i = 2; i <= N; i++) {
    edges.emplace_back(1, i);
  }
  int M = N - 1 + (N-1) * (N-2) / 2 - K;
  for (int i = 2; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      edges.emplace_back(i, j);
    }
  }
  cout << M << '\n';
  rep(i, M) {
    printf("%d %d\n", edges[i].first, edges[i].second);
  }
  return 0;
}