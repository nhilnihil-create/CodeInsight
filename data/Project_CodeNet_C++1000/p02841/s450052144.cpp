#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int M1, D1, M2, D2;
  cin >> M1 >> D1 >> M2 >> D2;
  cout << (M1 != M2 ? 1 : 0) << endl;
  return 0;
}
