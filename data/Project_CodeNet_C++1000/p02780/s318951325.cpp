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
  long long p[N];
  for (int i = 0; i < N; i++) cin >> p[i];
  long long sum = 0;
  for (int i = 0; i < K; i++) sum += p[i];
  long long ans = sum;
  for (int j = K; j < N; j++) {
    sum -= p[j - K];
    sum += p[j];
    ans = max(ans, sum);
  }
  printf("%lf\n", (ans + K) * 0.5);
  return 0;
}
