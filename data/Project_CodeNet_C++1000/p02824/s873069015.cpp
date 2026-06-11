#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.rbegin(), A.rend());

  ll l = 0, r = N;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    ll thre = A[P - 1];
    bool ok = false;

    if (A[m] + M < thre) {
      ok = false;
    } else {
      ll sum = 0;
      for (ll i = 0; i < N; i++) {
        if (A[i] > thre) sum += M;
        else sum += min(A[m] + M - A[i], M);
      }
      // cout << m << ' ' << sum << '\n';
      if (sum >= V * M) ok = true;
    }

    if (ok) l = m; else r = m;
  }
  cout << (l + 1) << '\n';
  return 0;
}