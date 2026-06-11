#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main() {
  ll N;
  ll Q;
  cin >> N >> Q;
  auto ft = atcoder::fenwick_tree<ll>(N);
  REP(i, N) {
    ll a;
    cin >> a;
    ft.add(i, a);
  }
  REP(i, Q) {
    ll t;
    cin >> t;
    if (t == 0) {
      ll p;
      ll x;
      cin >> p >> x;
      ft.add(p, x);
    } else {
      ll l;
      ll r;
      cin >> l >> r;
      cout << ft.sum(l, r) << endl;
    }
  }
  return 0;
}
