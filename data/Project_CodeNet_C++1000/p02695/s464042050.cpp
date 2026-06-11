#include <bits/stdc++.h>

using usize = size_t;
using u64 = uint64_t;

usize n;
u64 m;
std::vector<std::tuple<usize, usize, u64, u64>> QS;
std::vector<u64> SQ;

u64 dfs();
int main() {
  usize q;
  std::cin >> n >> m >> q;
  QS.resize(q);
  for (usize i = 0; i < q; i++) {
    usize a, b;
    u64 c, d;
    std::cin >> a >> b >> c >> d;
    QS[i] = std::make_tuple(a - 1, b - 1, c, d);
  }
  std::cout << dfs() << '\n';
}

u64 dfs() {
  u64 res = 0;
  if (SQ.size() == n) {
    for (auto q : QS) {
      usize a, b;
      u64 c, d;
      std::tie(a, b, c, d) = q;
      if (SQ[b] - SQ[a] == c) res += d;
    }
  } else {
    u64 last = SQ.empty() ? 1 : SQ[SQ.size() - 1];
    for (u64 x = last; x <= m; x++) {
      SQ.push_back(x);
      res = std::max(res, dfs());
      SQ.pop_back();
    }
  }
  return res;
}
