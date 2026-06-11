#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  map<char, vector<ll>> ind;
  for (ll i = 0; i < n; i++) {
    ind[s[i]].push_back(i);
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      if (s[i] == s[j]) continue;
      set<char> cols = {'R', 'G', 'B'};
      cols.erase(s[i]);
      cols.erase(s[j]);
      char c = *cols.begin();

      auto begin = lower_bound(ind[c].begin(), ind[c].end(), j + 1);
      auto exist = binary_search(begin, ind[c].end(), 2*j - i);
      if (exist) ans += ind[c].end() - begin - 1;
      else ans += ind[c].end() - begin;
    }
  }

  cout << ans << endl;
}
