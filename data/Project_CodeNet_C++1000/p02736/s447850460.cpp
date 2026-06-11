#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    a[i] = ch - '1';
  }
  bool ones = false;
  for (auto& i : a) if (i == 1) ones = true;
  if (ones) {
    for (auto& i : a) if (i == 2) i = 0;
  } else {
    for (auto& i : a) if (i == 2) i = 1;
  }
  auto doit = [] (int n, const vector<int>& a) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (((n - 1) & i) == i) res ^= a[i];
    }
    return res;
  };
  cout << (ones ? doit(n, a) : 2 * doit(n, a)) << endl;
  return 0;
}