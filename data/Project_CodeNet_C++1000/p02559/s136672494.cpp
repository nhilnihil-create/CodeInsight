#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N, Q;
  cin >> N >> Q;
  fenwick_tree<ll> fw(N);
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    fw.add(i, a);
  }

  for (int i = 0; i < Q; i++) {
    ll p, q, r;
    cin >> p >> q >> r;
    if (p == 0) {
      fw.add(q, r);
    } else if (p == 1) {
      cout << fw.sum(q, r) << "\n";
    }
  }
}