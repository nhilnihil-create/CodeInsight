#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  int ans = P + Q + R - max({P, Q, R});
  cout << ans << '\n';
  return 0;
}