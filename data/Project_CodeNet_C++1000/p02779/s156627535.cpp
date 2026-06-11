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
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  bool isok = true;
  for (int i = 0; i + 1 < N; i++) {
    isok &= A[i] != A[i + 1];
  }
  cout << (isok ? "YES" : "NO") << endl;
  return 0;
}
