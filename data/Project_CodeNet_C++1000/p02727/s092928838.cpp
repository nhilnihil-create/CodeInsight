#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A), q(B), r(C);
  REP(i, A) cin >> p[i];
  REP(i, B) cin >> q[i];
  REP(i, C) cin >> r[i];
  sort(p.begin(), p.end(), greater<>());
  sort(q.begin(), q.end(), greater<>());
  REP(i, X) { r.push_back(p[i]); }
  REP(i, Y) { r.push_back(q[i]); }
  sort(r.begin(), r.end(), greater<>());
  ll ans = 0;
  REP(i, X + Y) { ans += r[i]; }
  cout << ans << endl;
}