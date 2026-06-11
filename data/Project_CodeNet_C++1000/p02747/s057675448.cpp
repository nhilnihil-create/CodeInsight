#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while (0)
#define chmin(x, v) do { x = min(x, v); } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  string s;
  cin >> s;
  if (s.size() % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  for (ll i=0; i<s.size(); i+=2) {
    if (s[i] != 'h' || s[i+1] != 'i') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
