#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 1, ans = n;
  rep(_, n) {
    int a;
    cin >> a;
    if (a == cnt) {
      ans--;
      cnt++;
    }
  }
  if (ans == n) {
    cout << -1;
  } else {
    cout << ans;
  }
  return 0;
}
