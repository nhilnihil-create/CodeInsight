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
  string S; cin >> S;

  int cnt = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] == S[i + 1]) ++cnt;
  }
  cout << min(cnt + K * 2, N - 1) << endl;
}
