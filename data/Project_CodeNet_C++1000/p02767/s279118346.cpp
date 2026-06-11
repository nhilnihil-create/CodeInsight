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
  int X[N];
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  };
  long long ans = INT_MAX;
  for (int P = 0; P <= 100; P++) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      sum += (X[i] - P) * (X[i] - P);
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
