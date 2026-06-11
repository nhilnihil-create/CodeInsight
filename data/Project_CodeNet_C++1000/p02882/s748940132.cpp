#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define REVERSE(x) reverse(ALL(x))
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = 3.141592653589793238462643383279;
ll getDigit(ll x) {
  return x == 0 ? 1 : log10(x) + 1;
}

signed main() {
  ld A, B, X;
  cin >> A >> B >> X;
  if (A * A * B == X) {
    COUTF(0.0);
    return 0;
  }

  ld area = X / A;
  debug(area);
  ld tan;
  if (area <= 0.5 * A * B) {
    // debug(1);
    // tan = (2 * area - A * B) / (B * B);
    tan = (2 * area) / (B * B);
  } else {
    tan = (A * A) / (2 * (area - A * B));
  }
  // tan = abs(tan);
  debug(tan);
  ld ans = atanl(tan) / PI * 180;
  debug(ans);
  if (area <= 0.5 * A * B) {
    COUTF(90 - ans);
  } else {
    COUTF(90 + ans);
  }

  return 0;
}