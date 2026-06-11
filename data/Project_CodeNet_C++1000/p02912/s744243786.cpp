#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  multiset<int> s;
  rep(i, n) s.insert(a[i]);

  rep(i, m) {
    auto max = *s.rbegin();
    s.erase(--s.end());
    s.insert(max / 2);
  }
  ll ans = 0;
  for (auto i : s) ans += i;

  cout << ans << endl;
}
