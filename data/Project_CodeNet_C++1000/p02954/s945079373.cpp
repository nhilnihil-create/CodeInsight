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
  string S;
  cin >> S;
  S = S + 'R';
  ll countR = 0;
  ll countL = 0;
  char before = '-';
  rep(i, S.size()) {
    char s = S[i];
    if (s == 'R') {
      countR++;
    }
    if (s == 'L') {
      countL++;
    }
    if (s == 'R' && before == 'L') {
      // debug(i);
      // debug(countR);
      // debug(countL);
      countR--;
      ll migi = countR / 2 + countL / 2 + countL % 2;
      ll hidari = countR / 2 + countL / 2 + countR % 2;

      rep(a, countR) {
        if (a == countR - 1) {
          cout << hidari << " ";
        } else {
          cout << 0 << " ";
        }
      }
      rep(b, countL) {
        if (b == 0) {
          cout << migi << " ";
        } else {
          cout << 0 << " ";
        }
      }
      countR = 1;
      countL = 0;
    }
    before = s;
  }
  ENDL;
  return 0;
}