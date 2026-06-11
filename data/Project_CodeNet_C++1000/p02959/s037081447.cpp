#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> mon(n+1);
  vector<int> b(n);
  rep(i, n+1) cin >> mon[i];
  rep(i, n) cin >> b[i];
  ll cnt = 0;
  rep(i, n) {
    if (b[i] > mon[i]) {
      cnt += mon[i];
      b[i] -= mon[i];
      int x = min(b[i], mon[i+1]);
      cnt += x;
      mon[i+1] -= x;
    } else {
      cnt += b[i];
      b[i] = 0;
    }
  }
  cout << cnt << '\n';
  return 0;
}