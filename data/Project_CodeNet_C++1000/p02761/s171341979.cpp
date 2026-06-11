#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, m, mxs = 0;
  cin >> n >> m;
  vector<ll> s(m), c(m);
  map<ll, ll> mp;
  rep(i, m) {
    cin >> s[i] >> c[i];
    s[i]--;
    if (mp[s[i]] && mp[s[i]] != c[i]) {
      puts("-1");
      return 0;
    }
    mp[s[i]] = c[i];
  }

  rep(i, 1000) {
    string S = to_string(i);
    if ((int)S.size() != n) continue;
    bool ok = true;
    for (auto m : mp)
      if (S[m.first] - '0' != m.second) {
        ok = false;
        break;
      }

    if (ok) {
      cout << i << endl;
      return 0;
    }
  }

  puts("-1");
  return 0;
}