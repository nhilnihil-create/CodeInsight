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
  int N, K; cin >> N >> K;
  int L = (N-1)*(N-2)/2;
  if (K > L) {
    cout << -1 << endl;
    return 0;
  }

  int N2 = (N-1) + (L-K);
  cout << N2 << endl;

  for (int i = 2; i <= N; ++i) {
    cout << 1 << " " << i << endl;
  }
  N2 -= N - 1;

  for (int i = 2; i <= N && N2 > 0; ++i) {
    for (int j = i + 1; j <= N && N2 > 0; ++j) {
      cout << i << " " << j << endl;
      --N2;
    }
  }
}
