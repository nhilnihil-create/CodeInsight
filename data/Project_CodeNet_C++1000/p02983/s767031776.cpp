#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll l, r;
  cin >> l >> r;

  set<int> mods;
  for (ll i = l; i <= r; i++) {
    int mod = i % 2019;
    mods.insert(mod);
    if (mods.size() >= 2019) break;
  }

  vector<int> m;
  for (auto itr = mods.begin(); itr != mods.end(); itr++) {
    m.push_back(*itr);
  }

  int ans = 2020;
  for (int i = 0; i < m.size(); i++) {
    for (int j = i + 1; j < m.size(); j++) {
      ans = min(ans, (m[i] * m[j]) % 2019);
    }
  }

  cout << ans << endl;
}
