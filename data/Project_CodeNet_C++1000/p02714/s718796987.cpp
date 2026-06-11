#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <numeric>
#include <map>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
string s;

vi r;
vi g;
vi b;

void input() {
  r.clear();
  g.clear();
  b.clear();

  cin >> n >> s;
}

ll cnt(vi& a, vi& b, vi& c) {
  ll ans = 0;

  for (int i = 0; i < (int)a.size(); ++i) {
    auto it1 = upper_bound(b.cbegin(), b.cend(), a[i]);

    if (it1 == b.cend())
      break;

    for (int j = it1 - b.cbegin(); j < (int)b.size(); ++j) {
      auto it2 = upper_bound(c.cbegin(), c.cend(), b[j]);

      if (it2 == c.cend())
        break;

      for (int k = it2 - c.cbegin(); k < (int)c.size(); ++k) {
        if (b[j] - a[i] < c[k] - b[j]) {
          ans += (int)c.size() - k;

          break;
        }

        if (b[j] - a[i] != c[k] - b[j])
          ++ans;
      }
    }
  }

  return ans;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      r.push_back(i);
    } else if (s[i] == 'G') {
      g.push_back(i);
    } else {
      b.push_back(i);
    }
  }

  vi p(3);
  iota(p.begin(), p.end(), 0);

  map<int, vi> t = {
    {0, r},
    {1, b},
    {2, g}
  };

  ll ans = 0;

  do {
    ans += cnt(t[p[0]], t[p[1]], t[p[2]]);
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}