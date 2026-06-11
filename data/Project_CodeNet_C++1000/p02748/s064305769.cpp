#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, M; cin >> A >> B >> M;
  vector<int> a(A), b(B), x(M), y(M), c(M);
  const int INF = 100005;
  int amin = INF, bmin = INF;
  rep(i,A) {
    cin >> a[i];
    amin = min(amin, a[i]);
  }
  rep(i,B) {
    cin >> b[i];
    bmin = min(bmin, b[i]);
  }
  int ans = amin + bmin;
  rep(i,M) {
    cin >> x[i] >> y[i] >> c[i];
    ans = min(ans, a[x[i]-1] + b[y[i]-1] -c[i]);
  }
  cout << ans << endl;
  return 0;
}