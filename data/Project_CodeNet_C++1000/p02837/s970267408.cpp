#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

llong N;
vector<vector<lpair>> A;

int main() {
  cin >> N;
  A.resize(N);
  for (auto &in: A) {
    llong a;
    cin >> a;
    for (int i = 0; i < a; i++) {
      llong x, y;
      cin >> x >> y;
      in.push_back(lpair(x-1, y));
    }
  }

  llong ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    bool ok = true;
    for (int j = 0; j < N; j++) {
      if (!((i>>j)&1)) continue;
      for (auto a: A[j]) {
        ok &= ((i&(1<<a.first)) > 0) == a.second;
      }
    }
    if (ok) {
      ans = max(ans, llong(__builtin_popcountll(i)));
    }
  }

  cout << ans << endl;

  return 0;
}