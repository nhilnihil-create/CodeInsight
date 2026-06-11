#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, L;
  cin >> N >> L;
  int org = (N * (N + 1) / 2) - N + N * L;
  int ans = 1 << 29;
  REPI(i, 1, N + 1) { ans = min(ans, abs(-L - i + 1)); }
  org >= 0 ? cout << org - ans << endl : cout << org + ans << endl;

  return 0;
}