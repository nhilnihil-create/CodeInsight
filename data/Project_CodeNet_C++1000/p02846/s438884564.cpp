#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

ll mod = 1000000007;



int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll da = t1 * a1 + t2 * a2;  // 1サイクルでAが移動する距離
  ll db = t1 * b1 + t2 * b2;  // 1サイクルでBが移動する距離

  if (da == db) {
    cout << "infinity" << endl;
    return 0;
  }

  if ((a1 > b1 && a2 > b2) || (a1 < b1 && a2 < b2)) {
    cout << 0 << endl;
    return 0;
  }

  if (a1 > b1) {
    swap(a1, b1);
    swap(a2, b2);
  }

  ll ans = 0;
  ll p = (a1 - b1) * t1;
  ll q = (a2 - b2) * t2;

  if (p + q < 0) {
    cout << 0 << endl;
    return 0;
  }

  ll s = (-p) / (p + q);
  ll t = (-p) % (p + q);

  if (t == 0) {
    cout << s * 2 << endl;
  } else {
    cout << s * 2 + 1 << endl;
  }

  return 0;
}
