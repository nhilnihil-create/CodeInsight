#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int N; cin >> N;
  vector<double> x(N), y(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

  std::vector<int> v(N);
  int cnt = 0;
  double total = 0;
  for (int i = 0; i < N; ++i) v[i] = i;
  do {
    for (int j = 1; j < N; ++j) {
      int a = v[j];
      int b = v[j-1];
      total += hypot(x[a]-x[b], y[a]-y[b]);
    }
    ++cnt;
  } while(next_permutation(v.begin(), v.end()));

  printf("%.9f\n", total/cnt);
}
