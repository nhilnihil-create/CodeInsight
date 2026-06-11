#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;
 
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  string ans(N, '?');
  bool isok = true;
  for (int i = 0; i < M; i++) {
    int s, c;
    cin >> s >> c;
    s--;
    if (ans[s] != '?' && ans[s] != '0' + c) {
      isok = false;
    }
    ans[s] = '0' + c;
  }
  if (!isok || (N > 1 && ans[0] == '0')) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < N; i++)
      if (ans[i] == '?') {
        ans[i] = '0' + (i || N == 1 ? 0 : 1);
      }
    cout << ans << endl;
  }
  return 0;
}