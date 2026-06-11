#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong N;
  vector<llong> A;

  cin >> N;
  A.resize(N + 1);
  map<llong, llong> m;
  llong ans = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    ans += m[i - A[i]];
    m[i + A[i]]++;
  }

  cout << ans << endl;

  return 0;
}