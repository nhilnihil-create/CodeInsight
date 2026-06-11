#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ((int)(x).size())

typedef map<int, int> M;
typedef pair<int, int> P;
typedef long long ll;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  REP(i, k) {
    if (b >= c) {
      c *= 2;
    } else if (a >= b) {
      b *= 2;
    } else {
      break;
    }
  }
  if (a < b && b < c) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
