#include <algorithm>
#include <cstdio>
#include <vector>

static const size_t n_max = 100000;
static size_t parents[n_max];
static int depths[n_max];
static std::vector<size_t> children[n_max];

void rec(size_t i, int d) {
  depths[i] = d;
  for (auto&& c : children[i])
    rec(c, d + 1);
}

int main() {
  size_t n;
  scanf("%zu\n", &n);
  std::fill(parents, parents + n, size_t(-1));
  for (size_t i = 0; i < n; i++) {
    size_t j, k;
    scanf("%zu%zu", &j, &k);
    for (size_t l = 0; l < k; l++) {
      size_t c;
      scanf("%zu", &c);
      children[j].push_back(c);
      parents[c] = j;
    }
  }
  rec(std::find(parents, parents + n, size_t(-1)) - parents, 0);
  for (size_t i = 0; i < n; i++) {
    printf("node %zu: parent = %d, depth = %d, %s, [",
           i, int(parents[i]), depths[i],
           parents[i] == size_t(-1) ? "root" : children[i].size() ? "internal node" : "leaf");
    if (children[i].size()) {
      for (size_t j = 0; j < children[i].size() - 1; j++)
        printf("%zu, ", children[i][j]);
      printf("%zu]\n", children[i][children[i].size()-1]);
    } else
      puts("]");
  }
  return 0;
}