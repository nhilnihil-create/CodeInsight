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

const int N = 200010;

int n;
int a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  ll ans = 0;
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i)
    q.emplace(b[i], i);
  while (!q.empty()) {
    int p, v;
    tie(v, p) = q.top(); q.pop();
    if (b[p] == a[p]) continue;
    if (b[p] < a[p]) {
      puts("-1");
      return 0;
    }
    int s = b[(p + 1) % n] + b[(p + n - 1) % n];
    if (b[p] < s) {
      puts("-1");
      return 0;
    }
    if (a[p] >= s) {
      if ((b[p] - a[p]) % s == 0) {
        ans += (b[p] - a[p]) / s;
        b[p] = a[p];
        continue;
      } else {
        puts("-1");
        return 0;
      }
    } else {
      ans += b[p] / s;
      b[p] %= s;
    }
    if (b[p] < a[p]) {
      puts("-1");
      return 0;
    }
    q.emplace(b[p], p);
  }
  printf("%lld\n", ans);
  return 0;
}
