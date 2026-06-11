#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll M; cin >> M;
  vector<ll> l(M, 0), r(M, 0);

  if (M % 2 == 0) {
    for (ll i = 0; i < N; i++) {
      if ((i + 1) >= M - i) break;
      l[i] = i + 1;
      r[i] = M - i;
    }
    for (ll i = 0; i < N; i++) {
      if ((M + i + 1) >= 2 * M + 1 - i) break;
      l[i + M / 2] = M + i + 1;
      r[i + M / 2] = 2 * M + 1 - i;
    }
  } else {
    for (ll i = 0; i < N; i++) {
      if ((i + 1) >= M + 1 - i) break;
      l[i] = i + 1;
      r[i] = M + 1 - i;
    }
    for (ll i = 0; i < N; i++) {
      if ((M + i + 2) >= 2 * M + 1 - i) break;
      l[i + (M + 1) / 2] = M + i + 2;
      r[i + (M + 1) / 2] = 2 * M + 1 - i;
    }
  }

  for (ll i = 0; i < M; i++) {
    cout << l[i] << ' ' << r[i] << '\n';
  }
  return 0;
}