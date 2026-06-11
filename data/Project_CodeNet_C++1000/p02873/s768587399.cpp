#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  string s;
  cin >> s;
  vector<int> a(s.size() + 1);
  rep(i, s.size()) {
    if (s[i] == '<') {
      a[i + 1] = a[i] + 1;
    }
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '>') {
      a[i] = max(a[i], a[i + 1] + 1);
    }
  }
  ll ans = 0;
  rep(i, s.size() + 1) ans += a[i];
  cout << ans << endl;
  return 0;
}