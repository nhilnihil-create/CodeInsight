#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll X) {
  vector<bool> dp(100001, false);  // i円の買い物ができるならYes
  dp.at(0) = true;
  FOR(i, 1, 100) { dp.at(i) = false; }
  FOR(i, 100, 106) { dp.at(i) = true; }
  int idx = 106;
  while (idx <= X) {
    if (dp.at(idx - 100) || dp.at(idx - 101) || dp.at(idx - 102) ||
        dp.at(idx - 103) || dp.at(idx - 104) || dp.at(idx - 105)) {
      dp.at(idx) = true;
    }
    idx++;
  }

  int result = dp.at(X) ? 1 : 0;
  cout << result << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll X;
  cin >> X;
  solve(X);

  return 0;
}
