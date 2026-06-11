#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, X;
  cin >> N >> X;
  int ans = 0;
  int l;
  vector<int> D(N + 1, 0);
  REPI(i, 1, N + 1) {
    cin >> l;
    D.at(i) = D.at(i - 1) + l;
  }

  REP(i, N + 1) {
    if (D.at(i) <= X) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
