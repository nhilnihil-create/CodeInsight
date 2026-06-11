#include <bits/stdc++.h>

typedef long long int64;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int counter(int x) {
  if (x == 0)
    return 0;
  return counter(x >> 1) + (x & 1);
}

int main() {
  int N;
  int A[20];
  int x[20][20], y[20][20];

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
    for (int j = 1; j <= A[i]; j++) {
      std::cin >> x[i][j] >> y[i][j];
    }
  }

  int maxv = 0;
  for (int bits = 1; bits < (1 << N); bits++) {
    bool ok = true;
    for (int i = 1; i <= N; i++) {
      if (!(bits & (1 << (i - 1))))
        continue;
      for (int j = 1; j <= A[i]; j++) {
        if (((bits >> (x[i][j] - 1)) & 1) ^ y[i][j])
          ok = false;
      }
    }
    if (ok)
      maxv = max(maxv, counter(bits));
  }

  std::cout << maxv << std::endl;
  return 0;
}
