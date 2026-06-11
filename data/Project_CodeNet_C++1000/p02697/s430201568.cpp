#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N, M;
  cin >> N >> M;

  int a = 0, b = 1;
  rep(i, M) {
    cout << a + 1 << " " << b + 1 << "\n";

    if (N % 2 == 0 && i + 1 == N / 4) {
      b++;
    }
    a = (a + N - 1) % N;
    b = (b + 1) % N;
  }

  return 0;
}