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

void solve(long long N, long long Q, std::vector<long long> t, std::vector<long long> u, std::vector<long long> v) {
  auto dsu = atcoder::dsu(N);
  REP(i, Q) {
    if (t[i] == 0) {
      dsu.merge(u[i], v[i]);
    } else {
      cout << (dsu.same(u[i], v[i]) ? 1 : 0) << endl;
    }
  }
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long Q;
  scanf("%lld", &Q);
  std::vector<long long> t(Q);
  std::vector<long long> u(Q);
  std::vector<long long> v(Q);
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &t[i]);
    scanf("%lld", &u[i]);
    scanf("%lld", &v[i]);
  }
  solve(N, Q, std::move(t), std::move(u), std::move(v));
  return 0;
}
