#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                             \
  cerr << __LINE__ << ": " << #x << " = {";          \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) { \
    cerr << ((hoge) ? "," : "") << x[hoge];          \
  }                                                  \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  long long P;
  cin >> N >> P;
  string S;
  cin >> S;
  long long ans = 0;
  if (P == 2 || P == 5) {
    for (long long i = 0; i < N; i++) {
      if ((S[i] - '0') % P == 0) ans += i + 1;
    }
  } else {
    long long sum = 0;
    long long cnt[P];
    fill(cnt, cnt + P, 0);
    long long pw10 = 1;
    for (int i = N - 1; i >= 0; i--) {
      sum = (sum + pw10 * (S[i] - '0')) % P;
      cnt[sum]++;
      pw10 = pw10 * 10 % P;
      debug(sum);
    }
    debugArray(cnt, P);
    ans = cnt[0];
    for (int i = 0; i < P; i++) ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
