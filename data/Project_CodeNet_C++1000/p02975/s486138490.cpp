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

const int N = 100010;

int n;
int a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  if (count(a + 1, a + n + 1, 0) == n) {
    puts("Yes");
    return 0;
  }
  if (n % 3) {
    puts("No");
    return 0;
  }
  sort(a + 1, a + n + 1);
  copy(a + 1, a + n + 1, b + 1);
  int m = unique(b + 1, b + n + 1) - b - 1;
  if (m == 2 && b[1] == 0 && count(a + 1, a + n + 1, 0) == n / 3) {
    puts("Yes");
  } else if (m == 3 && (b[1] == (b[2] ^ b[3])) && count(a + 1, a + n + 1, b[1]) == n / 3 && count(a + 1, a + n + 1, b[2]) == n / 3 && count(a + 1, a + n + 1, b[3]) == n / 3)
    puts("Yes");
  else
    puts("No");
  return 0;
}