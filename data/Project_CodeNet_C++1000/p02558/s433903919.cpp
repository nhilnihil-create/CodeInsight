
#include <vector>

namespace cp {

struct union_find {
  std::vector<int> p; union_find(int n) : p(n, -1) { }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool unite(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp)       return false;
    if (p[xp] > p[yp])  std::swap(xp,yp);
    p[xp] += p[yp], p[yp] = xp;
    return true;
  }
  int size(int x) { return -p[find(x)]; }
};

}  // namespace cp

#include <cstdio>

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  cp::union_find d(n);
  for (int i = 0; i < q; i++) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    if (t == 0)
      d.unite(u, v);
    else
      printf("%d\n", d.find(u) == d.find(v));
  }
  return 0;
}
