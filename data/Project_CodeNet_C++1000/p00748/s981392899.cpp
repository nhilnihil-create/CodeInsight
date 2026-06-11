#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int N=1000000;

int main() {
  std::vector<int> all, odd;

  for (int i=1; true; ++i) {
    int n=i*(i+1)*(i+2)/6;
    if (n > 1000000)
      break;

    all.push_back(n);
    if (n % 2 == 1)
      odd.push_back(n);
  }

  std::vector<int> dp_all(N, N), dp_odd(N, N);
  dp_all[0] = dp_odd[0] = 0;
  dp_all[1] = dp_odd[1] = 1;
  for (int i=1; i<N; ++i) {
    for (int a: all) {
      if (a > i) break;

      dp_all[i] = std::min(dp_all[i], dp_all[i-a]+1);
    }

    for (int o: odd) {
      if (o > i) break;

      dp_odd[i] = std::min(dp_odd[i], dp_odd[i-o]+1);
    }
  }

  while (true) {
    int q;
    scanf("%d", &q);
    if (q == 0)
      break;

    printf("%d %d\n", dp_all[q], dp_odd[q]);
  }

  return 0;
}