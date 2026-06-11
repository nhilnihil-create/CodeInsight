#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, a;
  cin >> n;
  vector<int> as(n);
  rep(i, n) {
    cin >> a;
    a--;
    as[i] = a;
  }
  int id = 0;
  int ans = 0;
  rep(i, n) {
    if (as[i] != id) {
      ans++;
    } else {
      id++;
    }
  }
  if (ans == n) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
