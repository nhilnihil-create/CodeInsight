#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> P;
  vector<ll> C;

  int p;
  for (int i = 0; i < N; ++i) {
    cin >> p;

    P.push_back(p - 1);
  }

  ll c;
  for (int i = 0; i < N; ++i) {
    cin >> c;

    C.push_back(c);
  }

  ll ans = LLONG_MIN;

  for (int i = 0; i < N; ++i) {
    int cur = i;
    ll point = 0;

    ll loopSize = 1;
    int idx = P[i];
    ll loopSum = C[idx];

    while (idx != i) {
      idx = P[idx];
      loopSum += C[idx];
      loopSize += 1;
    }

    if (loopSum < 0) {
      loopSum = 0;
    }

    for (ll k = 1; k <= min((ll) K, loopSize); ++k) {
      cur = P[cur];
      point += C[cur];

      ll loopCnt = (K - k) / loopSize;
      ll score = point + loopCnt * loopSum;

      /*
      fprintf(stderr, "[%d, k: %lld, cur: %d, point: %lld, loopSize: %lld, loopCnt: %lld, score: %lld]\n",
          i, k, cur, point, loopSize, loopCnt, score);
          */
      ans = max(ans, score);
    }
  }

  cout << ans << endl;

  return 0;
}
