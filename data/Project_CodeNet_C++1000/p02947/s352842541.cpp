#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; i++) cin >> ss[i];

  map<string, ll> m;
  for (int i = 0; i < n; i++) {
    auto s = ss[i];
    sort(s.begin(), s.end());
    if (m.count(s) == 0) m[s] = 0;
    m[s]++;
  }

  ll ans(0);
  for (auto ele : m) {
    ans += ele.second * (ele.second - 1) / 2;
  }
  cout << ans << endl;
}
