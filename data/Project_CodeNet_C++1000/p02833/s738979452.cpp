#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  if (N == 0) {
    cout << 0;
  } else if (N % 2 != 0) {
    cout << 0;
  } else {
    N /= 2;
    int64_t sum = 0;
    int64_t x = 5;
    while (x <= N) {
      sum += N / x;
      x *= 5;
    }
    cout << sum;
  }
  return 0;
}
