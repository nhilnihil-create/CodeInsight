#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> r(N + 1), g(N + 1), b(N + 1);
  for (int i = 1; i < N + 1; i++) {
    r[i] += r[i - 1] + (S[i - 1] == 'R');
    g[i] += g[i - 1] + (S[i - 1] == 'G');
    b[i] += b[i - 1] + (S[i - 1] == 'B');
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (S[i] == S[j]) continue;
      if ((S[i] == 'R' && S[j] == 'G') || (S[j] == 'R' && S[i] == 'G')) {
        ans += b[N] - b[j + 1];
        if (2 * j - i < N && S[2 * j - i] == 'B') ans--;
      }
      if ((S[i] == 'G' && S[j] == 'B') || (S[j] == 'G' && S[i] == 'B')) {
        ans += r[N] - r[j + 1];
        if (2 * j - i < N && S[2 * j - i] == 'R') ans--;
      }
      if ((S[i] == 'B' && S[j] == 'R') || (S[j] == 'B' && S[i] == 'R')) {
        ans += g[N] - g[j + 1];
        if (2 * j - i < N && S[2 * j - i] == 'G') ans--;
      }
    }
  }
  cout << ans << endl;
}