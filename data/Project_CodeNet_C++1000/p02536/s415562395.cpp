#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using ll = long long;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  dsu d(N);
  ll ans = N - 1;

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if(!d.same(x, y)){
      d.merge(x, y);
      ans--;
    }
  }

  cout << ans << '\n';
  return 0;
}