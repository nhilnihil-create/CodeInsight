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

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if(!d.same(x, y)){
      d.merge(x, y);
    }
  }

  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    A[i] = d.leader(i);
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  
  ll ans = A.size() - 1;
  cout << ans << '\n';
  return 0;
}