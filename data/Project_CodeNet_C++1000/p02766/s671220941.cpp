#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long N, K;
  cin >> N >> K;
  int ans = 0;
  while (N) {
    N /= K;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
