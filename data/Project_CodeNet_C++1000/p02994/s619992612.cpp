#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int N, L;
  cin >> N >> L;

  int a = L, b = L + N - 1;
  int d;
  if (a > 0) {
    d = a;
  } else if (b < 0) {
    d = b;
  } else {
    d = 0;
  }

  cout << N * L + N * (N - 1) / 2 - d << endl;

  return 0;
}