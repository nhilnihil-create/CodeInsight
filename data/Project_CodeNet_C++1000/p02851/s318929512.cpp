#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N + 1);
  for (ll i = 1; i <= N; ++i) {
    cin >> A[i];
  }

  if (K == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  vector<ll> S(N + 1);
  S[0] = 0;
  for (ll i = 1; i <= N; ++i) {
    S[i] = S[i - 1] + A[i];
  }

  vector<ll> X(N + 1);
  for (ll i = 0; i <= N; ++i) {
    X[i] = (S[i] - i + K) % K;
  }

  ll ans = 0;
  map<ll, ll> counts;
  counts[0]++;
  for (ll j = 1; j <= N; ++j) {
    ans += counts[X[j]];
    counts[X[j]]++;
    if (j - K + 1 >= 0) counts[X[j - K + 1]]--;
  }

  cout << ans << endl;
  
  return 0;
}
