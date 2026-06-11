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
#define SORT(x) sort(ALL(x))
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
  ll N;
  cin >> N;
  vector<P> v;
  rep(i, N) {
    ll A, B;
    cin >> A >> B;
    v.pb({B, A});  // firstが締め切り時間
  }

  SORT(v);
  ll keika = 0;
  rep(i, N) {
    keika += v[i].second;
    if (keika > v[i].first) {
      COUT("No");
      return 0;
    }
  }
  COUT("Yes");
  return 0;
}