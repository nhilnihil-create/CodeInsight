#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int M, D;
  cin >> M >> D;
  int c = 0;
  for (int i = 1; i <= D; i++) {
    if ((i / 10) < 2 || (i % 10) < 2) {
      continue;
    }
    if ((i / 10) * (i % 10) <= M) {
      //cout << i << endl;
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
