#include <bits/stdc++.h>
#include <atcoder/dsu.hpp>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
using namespace std;
using namespace atcoder;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2> bool chmin(T1 &l, const T2 &r);
template <class T1, class T2> bool chmax(T1 &l, const T2 &r);
template <class T1, class T2> void vadd(vector<T1> &v, T2 x);

#define int long long int

void solve(long long N, long long Q, std::vector<long long> t,
           std::vector<long long> u, std::vector<long long> v) {
             dsu d(N);
             rep(i, Q)
             if(t[i]) cout << d.same(u[i], v[i]) << endl;else d.merge(u[i], v[i]) ;
           }

signed main() {
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

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2> bool chmin(T1 &l, const T2 &r) {
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2> bool chmax(T1 &l, const T2 &r) {
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2> void vadd(vector<T1> &v, T2 x) {
  for (auto &s : v)
    s += T2(x);
}
