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
  string S; cin >> S;
  LL K; cin >> K;
  int N = S.size();

  LL cnt = 0;
  for (int i = 1; i < N; ++i) {
    if (S[i-1] == S[i]) {
      ++cnt; ++i;
    }
  }

  LL a = 0, b = 0;
  while (S[0] == S[a] && a < N) ++a;
  while (S[N-1] == S[N-b-1] && b < N) ++b;

  if (a == N) {
    cout << N * K / 2  << endl;
  } else if (S[0] != S.back()) {
    cout << cnt * K  << endl;
  } else {
    cout << cnt * K - (a/2 + b/2 - (a + b)/2) * (K-1) << endl;
  }
}
