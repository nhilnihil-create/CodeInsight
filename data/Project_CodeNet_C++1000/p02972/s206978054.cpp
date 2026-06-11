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
  vector<llong> a;

  cin >> N;
  a.resize(N);
  for (auto &in: a) {
    cin >> in;
  }

  vector<llong> ans(N + 1, 0);
  llong num = 0;
  bool ok = true;
  for (int i = N; i >= 1; i--) {
    llong sum = 0;
    for (int j = i; j <= N; j += i) {
      sum += ans[j];
    }
    if (sum % 2 != a[i - 1]) {
      ans[i] = 1;
      num++;
    }
  }

  cout << num << endl;
  for (int i = 1; i <= N; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}