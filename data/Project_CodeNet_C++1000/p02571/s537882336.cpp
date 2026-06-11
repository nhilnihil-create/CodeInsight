#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef map<ll, ll> M;
typedef pair<ll, ll> P;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ((ll)(x).size())

int main() {
  string s, t;
  cin >> s >> t;
  ll tmp, result = 1001;
  REP(i, SIZE(s) - SIZE(t) + 1) {
    tmp = 0;
    REP(j, SIZE(t)) {
      if (s[i+j] != t[j]) tmp++;
    }
    if (tmp < result) result = tmp;
  }
  cout << result << endl;
  return 0;
}
