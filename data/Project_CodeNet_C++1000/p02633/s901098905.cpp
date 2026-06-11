#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }
inline i64 gcd(i64 a, i64 b) {
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}
inline i64 lcm(i64 a, i64 b) {
  return a * b / gcd(a, b);
}

int main() {
  i64 x;
  cin >> x;
  cout << 360 / gcd(x, 360) << endl;
  return 0;
}
