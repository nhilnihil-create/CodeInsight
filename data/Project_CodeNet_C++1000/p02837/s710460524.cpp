#include <bits/stdc++.h>
using namespace std;

unsigned long long popcount(unsigned long long x) {
  x = ((x & 0xaaaaaaaaaaaaaaaaUL) >> 1) + (x & 0x5555555555555555UL);
  x = ((x & 0xccccccccccccccccUL) >> 2) + (x & 0x3333333333333333UL);
  x = ((x & 0xf0f0f0f0f0f0f0f0UL) >> 4) + (x & 0x0f0f0f0f0f0f0f0fUL);
  x = ((x & 0xff00ff00ff00ff00UL) >> 8) + (x & 0x00ff00ff00ff00ffUL);
  x = ((x & 0xffff0000ffff0000UL) >> 16) + (x & 0x0000ffff0000ffffUL);
  x = ((x & 0xffffffff00000000UL) >> 32) + (x & 0x00000000ffffffffUL);
  return x;
}

long long n;
long long memo[20][2] = {0};

long long solve();

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long tr = 0, fal = 0, x, y, a;
    cin >> a;
    for (int j = 0; j < a; ++j) {
      cin >> x >> y;
      --x;
      if (y)
        tr += 1LL << x;
      else
        fal += 1LL << x;
    }
    memo[i][1] = tr;
    memo[i][0] = fal;
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  int ans = 0;
  for (long long i = 0; i < (1LL << n); ++i) {
    bool ch = 1;
    for (int j = 0; j < n; ++j)
      if ((i >> j) & 1) {
        if ((i & memo[j][1]) != memo[j][1]) ch = 0;
        if ((~i & memo[j][0]) != memo[j][0]) ch = 0;
      }
    if (ch) ans = max(ans, (int)popcount(i));
  }
  return ans;
}
