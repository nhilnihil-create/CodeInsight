#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  bool isok = true;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    isok &= (A % 2 != 0) || (A % 3 == 0) || (A % 5 == 0);
  }
  cout << (isok ? "APPROVED" : "DENIED") << endl;

  return 0;
}
