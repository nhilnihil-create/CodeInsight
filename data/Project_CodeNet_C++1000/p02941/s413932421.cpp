#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
inline bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
inline bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vll a(n);
  rep(i, n){
    cin >> a[i];
  }
  vll b(n);
  rep(i, n){
    cin >> b[i];
  }
  priority_queue<pll> pq;
  rep(i, n){
    if(b[i] > a[i] && b[i] > b[(i-1+n)%n] + b[(i+1)%n]){
      pq.emplace(b[i], i);
    }
  }
  ll ans = 0;
  while(pq.size()){
    ll y, idx;
    tie(y, idx) = pq.top();
    pq.pop();
    ll x = b[(idx-1+n)%n];
    ll z = b[(idx+1)%n];
    ll tmp = min((x+y+z-max(x,z)-1)/(x+z), (x+y+z-1-a[idx])/(x+z));
    ans += tmp;
    b[idx] -= tmp*(x+z);
    dump(y, idx, tmp);
    if(b[idx] < a[idx] || tmp == 0){
      print(-1);
      return 0;
    }
    idx = (idx-1+n)%n;
    if(b[idx] > a[idx] && b[idx] > b[(idx-1+n)%n] + b[(idx+1)%n]){
      pq.emplace(b[idx], idx);
    }
    idx = (idx+2)%n;
    if(b[idx] > a[idx] && b[idx] > b[(idx-1+n)%n] + b[(idx+1)%n]){
      pq.emplace(b[idx], idx);
    }
  }
  if(a == b) print(ans);
  else print(-1);
}
