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

const int N = 100010, P = 1000000007;

int n;
char s[N * 2];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%s", &n, s + 1);
  s[0] = 'W';
  int cnt = 0, ans = 1;
  bool pre = false;
  for (int i = 1; i <= n * 2; ++i) {
    if ((s[i] == s[i - 1]) == pre) {
      ++cnt;
      pre = false;
    } else {
      ans = ans * (ll) cnt-- % P;
      pre = true;
    }
  }
  if (cnt) ans = 0;
  for (int i = 1; i <= n; ++i) ans = ans * (ll)i % P;
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
