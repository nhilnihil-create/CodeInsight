#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  vector<string> s = {"Sunny", "Cloudy", "Rainy"};
  string t;
  cin >> t;
  REP(i, SZ(s)) {
    if (s[i] == t) {
      cout << s[(i + 1) % SZ(s)] << endl;
      return 0;
    }
  }
}