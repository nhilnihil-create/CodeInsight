// https://atcoder.jp/contests/abc166/tasks/abc166_e

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,avx512f")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>

using uint = unsigned int;
signed main() {
  uint n;
  std::cin >> n;
  std::vector<uint> a;
  a.reserve(n);
  for (uint i = 0; i < n; ++i) { uint t; std::cin >> t; a.emplace_back(t); }

  std::vector<uint> ansv(16);
  for (uint i = 0; i < n; ++i) {
    for (uint j = i + 1; j < n; ++j) {
      ansv[i%16] += (j - i) == a[j] + a[i];
    }
  }

  long long ans = 0;
  for (const auto& x : ansv) { ans += x; }
  std::cout << ans << std::endl;

  return 0;

}