#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> R(A), G(B), T(C);
  REP(i, A) cin >> R[i];
  REP(i, B) cin >> G[i];
  REP(i, C) cin >> T[i];
  sort(R.begin(), R.end(), greater<int>());
  sort(G.begin(), G.end(), greater<int>());
  REP(i, X) T.push_back(R[i]);
  REP(i, Y) T.push_back(G[i]);
  sort(T.begin(), T.end(), greater<int>());
  ll ans = 0;
  REP(i, X + Y) { ans += T[i]; }
  cout << ans << endl;
}