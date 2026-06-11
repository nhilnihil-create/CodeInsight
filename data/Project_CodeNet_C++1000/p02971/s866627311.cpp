#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> s = a;
  sort(s.rbegin(), s.rend());
  rep(i, n) {
    int ans = s[0];
    if (a[i] == s[0]) ans = s[1];
    cout << ans << '\n';
  }
  return 0;
}