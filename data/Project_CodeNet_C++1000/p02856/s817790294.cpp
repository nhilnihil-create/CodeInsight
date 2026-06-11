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

pair<LL, LL> f(LL v1, LL v2) {
  LL v = v1 + v2;
  LL cnt = 0;
  while (v > 9) {
    LL k2 = v / 10;
    LL k1 = v % 10;
    v = k1 + k2;
    ++cnt;
  }
  return {v, cnt};
}

int main() {
  int M; cin >> M;
  LL keta = 0, sum = 0;
  for (int i = 0; i < M; ++i) {
    LL d, c; cin >> d >> c;
    sum += d * c;
    keta += c;
  }
  cout << (keta-1) + ((sum-1)/9) << endl;
}
