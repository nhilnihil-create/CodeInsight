#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  if (K == 1) {
    cout << 0 << endl;
  } else {
    cout << N - (K - 1) - 1 << endl;
  }
  return 0;
}
