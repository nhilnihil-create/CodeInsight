#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
P RetVec(P x, P y) { return P(x.first - y.first, x.second - y.second); }
int main() {
  int N;
  cin >> N;
  vector<P> Z(N);
  REP(i, N) cin >> Z[i].first >> Z[i].second;
  ll ans = N;
  REP(i, N) for (int j = 0; j < N; j++) {
    if (i == j) continue;
    P p = RetVec(Z[i], Z[j]);
    ll tmp = 0;
    REP(k, N) for (int l = 0; l < N; l++) {
      if (k == l) continue;
      if (RetVec(Z[k], Z[l]) == p) {
        tmp++;
      }
    }
    ans = min(ans, N - tmp);
  }
  cout << ans << endl;
}