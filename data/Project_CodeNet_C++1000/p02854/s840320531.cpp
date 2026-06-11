#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<ll> A(N);
  ll a;
  cin >> a;
  A.at(0) = a;
  REPI(i, 1, N) {
    cin >> a;
    A.at(i) = A.at(i - 1) + a;
  }

  ll ans = 1e10;
  REP(i, N) {
    ll tmp1 = A.at(i);
    ll tmp2 = A.at(N - 1) - A.at(i);
    ans = min(ans, abs(tmp2 - tmp1));
  }

  cout << ans << endl;

  return 0;
}
