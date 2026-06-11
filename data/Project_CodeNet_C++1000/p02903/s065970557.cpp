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
  int H, W, A, B; cin >> H >> W >> A >> B;
  for (int r = 0; r < B; ++r) {
    for (int c = 0; c < A; ++c) {
      cout << 0;
    }
    for (int c = A; c < W; ++c) {
      cout << 1;
    }
    cout << endl;
  }
  for (int r = B; r < H; ++r) {
    for (int c = 0; c < A; ++c) {
      cout << 1;
    }
    for (int c = A; c < W; ++c) {
      cout << 0;
    }
    cout << endl;
  }
}
