#include <iostream>
#include <atcoder/dsu>

int main() {
  int N, Q;
  std::cin >> N >> Q;
  atcoder::dsu dsu(N);
  for (int i = 0; i < Q; i++) {
    int type, u, v;
    std::cin >> type >> u >> v;
    if (type == 0) {
      dsu.merge(u,v);
    } else {
      if (dsu.same(u,v)) std::cout << 1 << std::endl;
      else std::cout << 0 << std::endl;
    }
  }
  return 0;
}
