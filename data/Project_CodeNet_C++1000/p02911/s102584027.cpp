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
  int N, K, Q; cin >> N >> K >> Q;
  vector<int> A(N, 0);
  for (int i = 0; i < Q; ++i) {
    int a; cin >> a; --a;
    A[a]++;
  }
  for (int i = 0; i < N; ++i) {
    int score = K + A[i] - Q;
    if (score > 0) cout << "Yes" << endl;
    else           cout << "No" << endl;
  }
}
