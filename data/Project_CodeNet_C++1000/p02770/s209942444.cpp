#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 5050;

int n;
int d[MAXN];
int qn, len, x, m;

int main() { 

  scanf("%d %d", &n, &qn);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }

  while (qn--) {
    scanf("%d %d %d", &len, &x, &m);
    long long ans = len - 1;

    long long last = x;

    for (int i = 0; i < n; i++) {
      if (i + 2 > len) {
        break;
      }
      long long curUse = 1 + (len - (i + 2)) / n;
      if (d[i] % m == 0) {
        ans -= curUse;
      }
      last += curUse * (d[i] % m);
    }

    ans -= (last / m - (x / m));

    printf("%lld\n", ans);
  }

  return 0;
}
