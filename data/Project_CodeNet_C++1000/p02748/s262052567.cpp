#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  REP(i, A) { cin >> a.at(i); }
  REP(i, B) { cin >> b.at(i); }

  vector<int> x(M);
  vector<int> y(M);
  vector<int> c(M);
  REP(i, M) { cin >> x.at(i) >> y.at(i) >> c.at(i); }

  int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
  REP(i, M) { ans = min(ans, a.at(x.at(i) - 1) + b.at(y.at(i) - 1) - c.at(i)); }
  cout << ans << endl;

  return 0;
}
