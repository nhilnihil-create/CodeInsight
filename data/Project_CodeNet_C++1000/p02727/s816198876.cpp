#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> P(A);
  rep(i, A) cin >> P[i];
  vector<ll> Q(B);
  rep(i, B) cin >> Q[i];
  vector<ll> R(C);
  rep(i, C) cin >> R[i];
  sort(P.begin(), P.end(), greater<ll>());
  sort(Q.begin(), Q.end(), greater<ll>());
  rep(i, X) R.push_back(P[i]);
  rep(i, Y) R.push_back(Q[i]);
  sort(R.begin(), R.end(), greater<ll>());
  // ll ans = 0;
  // rep(i, X+Y) ans += R[i];
  ll ans = accumulate(R.begin(), R.begin() + X + Y, 0LL);
  cout << ans << '\n';
  return 0;
}