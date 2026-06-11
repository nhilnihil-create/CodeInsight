#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

const int N = 1000000;
const int mod = 1e9 + 7;

int fac[N + 1];

#define pow abcdef
int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % mod;
  if (b % 2) return (t * a) % mod;
  return t;
}

void Main() {
  fac[0] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  int x, y;
  cin >> x >> y;
  int mx = 0, my = 0, a = 0, b = 0;
  while (mx <= x && my <= y) {
    if ((x - mx) % 2 == 0 && (x - mx) / 2 == y - my) {
      b = y - my;
      int ans = (fac[a + b] * pow(fac[a], mod - 2)) % mod;
      (ans *= pow(fac[b], mod - 2)) %= mod;
      cout << ans << '\n';
      return;
    }
    mx += 1;
    my += 2;
    a++;
  }
  cout << 0 << '\n';
}

signed main() {
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
