#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  double cnt = 0;
  for (int i = 1; i <= N; ++i) {
    if (i % 2 == 1) ++cnt;
  }
  printf("%.8f\n", cnt / N);
}
