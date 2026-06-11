#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int const BASE = 998244353;

ll f(int n, int m) {
  ll ans = 1;
  REP(i, m) { ans = ans * n % BASE; }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;

  cin >> N;
  vector<int> D(N);
  REP(i, N) { cin >> D[i]; }

  if (D[0] != 0) {
    cout << 0 << endl;
    return 0;
  }

  sort(D.begin(), D.end());
  ll ans = 1;
  int parent_count = 1;
  int children_count = 1;

  REPI(i, 0, N - 1) {
    if (D[i] == 0 && i > 0) {
      cout << 0 << endl;
      return 0;
    }

    if (D[i] != D[i + 1]) {
      if (D[i + 1] != D[i] + 1) {
        cout << 0 << endl;
        return 0;
      } else {
        ans = ans * f(parent_count, children_count) % BASE;
        parent_count = children_count;
      }
      children_count = 1;
    } else {
      ++children_count;
    }
  }

  ans = ans * f(parent_count, children_count) % BASE;

  cout << ans % BASE << endl;

  return 0;
}
