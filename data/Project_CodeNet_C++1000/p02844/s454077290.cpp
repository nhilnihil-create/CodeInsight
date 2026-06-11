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
  for (char a = '0'; a <= '9'; a++) {
    int i = S.find(a);
    if (i == string::npos) continue;
    for (int b = '0'; b <= '9'; b++) {
      int j = S.find(b, i + 1);
      if (j == string::npos) continue;
      for (int c = '0'; c <= '9'; c++) {
        int k = S.find(c, j + 1);
        if (k != string::npos) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
