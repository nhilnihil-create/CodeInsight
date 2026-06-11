#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

map<char, char> win;

int main() {
  int n, k;
  string t;
  map<char, int> p;
  cin >> n >> k >> p['r'] >> p['s'] >> p['p'];
  cin >> t;

  win['r'] = 'p';
  win['s'] = 'r';
  win['p'] = 's';

  ll ans = 0;
  string u(n, '-');
  for (int i = 0; i < k; i++) {
    char w = win[t[i]];
    ans += p[w];
    u[i] = w;
  }

  for (int i = k; i < n; i++) {
    char w = win[t[i]];
    if (w != u[i - k]) {
      ans += p[w];
      u[i] = w;
    }
  }
  cout << ans << endl;
}
