#include <bits/stdc++.h>

#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
using namespace std;
// ====

typedef long long ll;
const int MAXN = 1000100;

int main() {
  auto d = [&](int a, int b) -> int {
    return abs(a - b);
  };
  int n, x, y;
  cin >> n >> x >> y;
  if (x > y) swap(x, y);
  vector<int> ans(n + 1);
  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      int dst = min(d(i, j), d(i, x) + d(y, j) + 1);
      ++ans[dst];
    }
  }
  for (int i = 1; i < n; ++i) {
    cout << ans[i] << "\n";
  }
}
