#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

constexpr int NUM_BITS = 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  int64 xor_all = 0;
  for (int64 x : xs) {
    xor_all ^= x;
  }

  for (int i = 0; i < n; i++) {
    xs[i] &= ~xor_all;
  }

  int c = 0;
  for (int b = NUM_BITS - 1; b >= 0; b--) {
    int pivot_i = -1;
    for (int i = c; i < n; i++) {
      if (xs[i] & (1L << b)) {
        pivot_i = i;
        break;
      }
    }

    if (pivot_i < 0) continue;

    swap(xs[pivot_i], xs[c]);

    for (int i = 0; i < n; i++) {
      if (i == c) continue;
      if (xs[i] & (1L << b)) {
        xs[i] ^= xs[c];
      }
    }

    c++;
  }

  int64 xor_all_2 = 0;
  for (int i = 0; i < n; i++) {
    xor_all_2 ^= xs[i];
  }
  cout << xor_all + xor_all_2 * 2 << endl;
}