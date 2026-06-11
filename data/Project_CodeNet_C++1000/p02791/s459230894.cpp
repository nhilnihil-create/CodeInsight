#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> ps(n, 0);
  rep(i, n) { cin >> ps[i]; }
  int ans = 0;
  int m = ps[0];
  rep(i, n) {
    if (ps[i] == m) {
      ans++;
    }
    if (i != n - 1) {
      m = min(m, ps[i + 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
