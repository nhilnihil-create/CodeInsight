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
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i + 2 < N; i++) {
    if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') ans++;
  }
  cout << ans << endl;
  return 0;
}
