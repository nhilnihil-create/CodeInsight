#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef map<int, int> M;
typedef pair<int, int> P;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ((ll)(x).size())

int main() {
  int d, t, s;
  cin >> d >> t >> s;
  if (d <= s * t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
