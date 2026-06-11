#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll A, ll B, ll K) {
  ll r = A - K;
  if (r >= 0) {
    cout << r << " " << B << endl;
  } else {
    if (B + r >= 0) {
      cout << 0 << " " << B + r << endl;
    } else {
      cout << "0 0" << endl;
      ;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll A;
  scanf("%lld", &A);
  ll B;
  scanf("%lld", &B);
  ll K;
  scanf("%lld", &K);
  solve(A, B, K);
  return 0;
}
