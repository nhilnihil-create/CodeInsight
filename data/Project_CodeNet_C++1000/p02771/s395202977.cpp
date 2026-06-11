#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  if (a[0] == a[1]) {
    cout << (a[2] != a[0] ? "Yes" : "No") << endl;
  } else {
    cout << (a[2] == a[0] || a[2] == a[1] ? "Yes" : "No") << endl;
  }
  return 0;
}
