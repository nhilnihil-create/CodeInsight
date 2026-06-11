#include <atcoder/dsu>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, q;
  std::cin >> n >> q;
  atcoder::dsu uf(n);
  while (q--) {
    int t, u, v;
    std::cin >> t >> u >> v;
    if (t) {
      if (uf.same(u, v)) {
        std::cout << 1 << '\n';
      } else {
        std::cout << 0 << '\n';
      }
    } else {
      uf.merge(u, v);
    }
  }
  return 0;
}