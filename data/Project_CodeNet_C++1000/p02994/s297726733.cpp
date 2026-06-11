#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N, L; cin >> N >> L;
  int sum = 0, vmin = 1e9;;
  for (int i = 0; i < N; ++i) {
    sum += L + i;
    if (abs(vmin) >  abs(L + i)) {
      vmin = L + i;
    }
  }
  cout << sum - vmin << endl;
}
