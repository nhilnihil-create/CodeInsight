#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vl = vector<ll>;
using VVl = vector<Vl>;
const ll INF = 1e18;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int N, M, X;
  cin >> N >> M >> X;
  Vl c(N);
  VVl a(N, Vl(M));
  rep(i, 0, N) {
    cin >> c[i];
    rep(j, 0, M) cin >> a[i][j];
  }

  ll ans = INF;
  for (int b = 0; b < (1 << N); b++) {
    bitset<12> bs(b);
    Vl t(M, 0);
    ll sum = 0;

    rep(i, 0, N) {
      if (bs.test(i)) {
        sum += c[i];
        rep(j, 0, M) { t[j] += a[i][j]; }
      }

      bool ok = true;
      rep(j, 0, M) if (t[j] < X) {
        ok = false;
        break;
      }
      if (ok) ans = min(ans, sum);
    }
  }
  cout << ((ans == INF) ? -1 : ans) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}