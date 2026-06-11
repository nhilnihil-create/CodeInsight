#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
int main() {
  int H, W, M, ans{};
  cin >> H >> W >> M;
  vector<int> ch(H), cw(W), I(H), J(W);
  iota(begin(I), end(I), 0);
  iota(begin(J), end(J), 0);
  set<pair<int, int>> s;
  while (cin >> H >> W) ++ch[--H], ++cw[--W], s.insert({H, W});
  sort(begin(I), end(I), [&](int i, int j){return ch[i] > ch[j]; });
  sort(begin(J), end(J), [&](int i, int j){return cw[i] > cw[j]; });
  for (auto i : I) for (auto j : J)
      if (ch[i] + cw[j] <= ans) break;
      else ans = max(ans, ch[i] + cw[j] - (int)s.count({i, j}));
  cout << ans << endl;
}
