#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  int A, B, M;
  cin >> A >> B >> M;

  vector<int> va(A), vb(B);
  for (auto &a : va) {
    cin >> a;
  }
  for (auto &b: vb) {
    cin >> b;
  }

  int ans = *min_element(va.begin(), va.end()) + *min_element(vb.begin(), vb.end());

  while (M--) {
    int x, y, c;
    cin >> x >> y >> c;
    ans = min(va[x-1] + vb[y-1]-c, ans);
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
