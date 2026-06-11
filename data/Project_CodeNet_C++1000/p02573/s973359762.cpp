#include <iostream>
#include <vector>
#include <string>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int main() {
  int n, m; input >> n >> m;
  vector components (n, -1);
  vector sizes (n, 1);

  auto parent = [&] (int i) -> int {
	int j = i;
	while (components[j] != -1) {
	  j = components[j];
	}
	while (i != j) {
	  int tmp = components[i];
	  components[i] = j;
	  i = tmp;
	}
	return j;
  };

  auto merge = [&] (int i, int j) -> void {
	int p1 = parent (i);
	int p2 = parent (j);
	if (p1 == p2)
	  return;
	if (sizes[p1] < sizes[p2]) {
	  std::swap (p1, p2);
	  std::swap (i, j);
	}
	components[p2] = p1;
	sizes[p1] += sizes[p2];
  };

  for (int i=0; i<m; i++) {
	int a, b; input >> a >> b;
	merge (a-1, b-1);
  }

  int maxsz = 0;
  for (int sz : sizes)
	if (sz > maxsz)
	  maxsz = sz;
  std::cout << maxsz << std::endl;
}

