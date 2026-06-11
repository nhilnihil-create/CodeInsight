#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

vector<pair<long long, long long>> prime_factorize(long long N) {
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;

    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  long long N;
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  const auto &res = prime_factorize(N);
  for (auto p : res) {
    long long x = p.second;
    long long b = 1;
    while(b <= x) {
      x -= b;
      b++;
      ++ans;
    }
  }
  cout << ans << endl;
}
