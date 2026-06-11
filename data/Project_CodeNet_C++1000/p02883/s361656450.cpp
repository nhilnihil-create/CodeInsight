#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
  for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
  for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup \
  cin.tie(0);  \
  ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 1e9 + 7LL;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    os << v[i] << " ";
  }
  if (v.size() > 0) {
    os << v[v.size() - 1] << endl;
  }
  return os;
}

bool judge(vll& a, vll f, ll target, ll k){
  int sz = f.size();
  vll maxnumvec(sz);
  REP(i,sz){
    maxnumvec[i] = target / f[i];
  }
  sort(maxnumvec.begin(), maxnumvec.end());
  REP(i, sz) {
    if (maxnumvec[i] < a[i]){
      k -= a[i] - maxnumvec[i];
    }
    if (k < 0) return false;
  }
  return true;
}

int main() {
  ll n,k;
  cin >> n >> k;
  vll a(n), f(n);
  cin >> a >> f;
  sort(a.begin(), a.end());
  ll lo = -1, hi = 1e14;
  while (hi - lo > 1){
    ll mid = (lo + hi) / 2;
    if (judge(a, f, mid, k)){
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi << endl;
}