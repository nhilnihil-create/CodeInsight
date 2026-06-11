#line 1 "agc043_b.cpp"
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
using P = std::pair<int, int>;
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  vi a(n);
  string s;
  cin >> s;
  REP(i, n) { a[i] = s[i] - '1'; }

  int one = 0;
  REP(i, n) {
    if ((n - 1) == (i | (n - 1 - i))) {
      one = (one ^ (a[i] % 2));
    }
  }
  if (one == 1) {
    cout << 1 << endl;
    return 0;
  }

  REP(i, n) {
    if (a[i] == 1) {
      cout << 0 << endl;
      return 0;
    }
  }

  int two = 0;
  REP(i, n) {
    a[i] /= 2;
    if ((n - 1) == (i | (n - 1 - i))) {
      two = (two ^ (a[i] % 2));
    }
  }

  if (two == 1) {
    cout << 2 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
