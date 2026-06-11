#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b;}

int main() {
  // X = Ak/2 * (2*p + 1)
  // それぞれのAkが2で割れる回数が同じでなければならない
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  int time = 0; // 2で割れる回数
  while (A[0] % 2 == 0) {
    time++;
    A[0] /= 2;
  }
  rep(j, time) {
    for (int i = 1; i < N; i++) {
      if (A[i] & 1) {
        cout << 0 << '\n';
        return 0;
      } else {
        A[i] /= 2;
      }
    }
  }
  rep(i, N) {
    if (A[i] % 2 == 0) {
      cout << 0 << '\n';
      return 0;
    }
  }
  ll l = 1;
  rep(i, N) {
    l = lcm(l, (ll)A[i]);
  }
  ll coef = 1;
  rep(i, time-1) coef *= 2;
  ll ans = M / l / coef - (M / 2 / l / coef);
  cout << ans << '\n';
  return 0;
}