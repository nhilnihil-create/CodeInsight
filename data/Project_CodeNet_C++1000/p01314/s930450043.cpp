#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int Solve(int n) {
  int result = 0;
  for (int div = 2; div <= n; div++) {
    if (div % 2 == 1) {
      if (n % div == 0) {
        int median = n / div;
        if (median - (div / 2) >= 1) {
          // cerr << div << endl;
          result++;
        }
      }
    } else {
      if (n % div == div / 2) {
        int median = n / div;
        if (median - (div / 2 - 1) >= 1) {
          // cerr << div << endl;
          result++;
        }
      }
    }
  }
  return result;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    cout << Solve(n) << endl;
  }

  return 0;
}

