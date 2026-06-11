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
  int isac[N];
  fill(isac, isac + N, 0);
  int cntwa = 0;
  while (M--) {
    int p;
    string S;
    cin >> p >> S;
    p--;
    if (isac[p] > 0) continue;
    if (S == "AC") {
      cntwa -= isac[p];
      isac[p] = 1;
    } else if (isac[p] <= 0) {
      isac[p]--;
    }
  }
  int cntac = 0;
  for (int i = 0; i < N; i++) {
    cntac += isac[i] > 0;
  }
  cout << cntac << " " << cntwa << endl;
  return 0;
}
