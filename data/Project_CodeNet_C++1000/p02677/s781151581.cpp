#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int main() {
  IOS;
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double anglea = h * 30.0 + (m / 60.0) * 30.0;
  double angleb = m * 6.0;
  double cc = sqrt(
      abs(a * a + b * b -
          2.0 * a * b *
              cos((angleb - anglea) * 3.14159265358979323846264338 / 180.0)));

  cout << fixed << setprecision(20) << cc << endl;
}
