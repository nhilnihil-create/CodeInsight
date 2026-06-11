#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  if (N % 2 == 0) {
    N--;
  }
  cout << N / 2 << endl;
  return 0;
}
