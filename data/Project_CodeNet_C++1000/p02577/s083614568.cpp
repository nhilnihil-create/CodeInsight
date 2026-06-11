#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  string s;
  cin >> s;
  ll sm = 0;
  for (int i = 0; i < s.size(); i++) {
    sm += s[i] - '0';
  }
  if (sm % 9 == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
