#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j)
      printf("%d ", __builtin_ctz(i ^ j) + 1);
    putchar('\n');
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
