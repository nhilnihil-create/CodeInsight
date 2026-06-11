#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S, T;
  cin >> S >> T;
  int A, B;
  cin >> A >> B;
  string U;
  cin >> U;
  if (U == S)
    A--;
  else
    B--;
  cout << A << " " << B << endl;
  return 0;
}
