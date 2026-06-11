#include <bits/stdc++.h>
using namespace std;

// Loops
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define _rrep(i, n) rrepi(i, n, 0)
#define rrepi(i, a, b) for (int i = int(a) - 1; i >= int(b); --i)

#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define rrep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(xi, x) for (auto &&xi : x)
// Note: we can use rep(i,N) or rep(i,from,to)

// typedef
template <class T> using vec = vector<T>;
using ll = long long;
using vi = vec<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
using pii = pair<ll, ll>;

// Constants

// Shorter repr for frequently used terms
#define pb push_back
#define mp make_pair

// Algorithms
#define all(x) (x).begin(), (x).end()
#define uniq(v) v.erase(unique(all(v)), v.end())
#define perm(c)                                                                \
  sort(all(c));                                                                \
  for (bool c##p = 1; c##p; c##p = next_permutation(all(c)))

template <class T> pair<T, size_t> max(vector<T> &x) {
  auto it = max_element(all(x));
  return mp(*it, it - x.begin());
}
template <class T> pair<T, size_t> min(vector<T> &x) {
  auto it = min_element(all(x));
  return mp(*it, it - x.begin());
}

template <class T> inline bool chmax(T &maxval, const T &newval) {
  if (maxval < newval) {
    maxval = newval;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &minval, const T &newval) {
  if (minval > newval) {
    minval = newval;
    return 1;
  }
  return 0;
}

// Utilities
// Grid world utilities
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
#define inside(H, W, y, x) 0 <= (x) && (x) < (W) && 0 <= (y) && (y) < (H)

// Debug
#ifdef LOCAL
#include "dump.hpp"
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define dump(...)
#define debug(x)
#endif

// Paste snippets here!!

//

void solve(long long X, long long Y, long long A, long long B, long long C,
           std::vector<long long> p, std::vector<long long> q,
           std::vector<long long> r)
{
  sort(all(p), [](ll x, ll y){ return x>y; });
  sort(all(q), [](ll x, ll y){ return x>y; });
  sort(all(r), [](ll x, ll y){ return x>y; });
  
  ll gx = 0; ll gy = 0;
  rep(i,X){
    gx += p[i];
  }
  rep(i,Y){
    gy += q[i];
  }
  X--; Y--;
  int k = 0;  // index for r
  for(;;){
    if(X<0 && Y<0) break;
    if(X<0){
      if(q[Y]>r[k]) break;
      gy -= q[Y];
      gy += r[k];
      k++; Y--;
    } else if (Y<0){
      if(p[X]>r[k]) break;
      gx -= p[X];
      gx += r[k];
      k++; X--;
    } else {
      if(p[X]>q[Y]){
        if(q[Y]>r[k]) break;
        gy -= q[Y];
        gy += r[k];
        k++; Y--;
      }
      else {
        if(p[X]>r[k]) break;
        gx -= p[X];
        gx += r[k];
        k++; X--;
      }
    }
    if(k==r.size()) break;
  }
  cout << gx + gy << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); // Magic for faster cin
  cout.precision(12);
  long long X;
  std::cin >> X;
  long long Y;
  std::cin >> Y;
  long long A;
  std::cin >> A;
  long long B;
  std::cin >> B;
  long long C;
  std::cin >> C;
  std::vector<long long> p(A);
  for (int i = 0; i < A; i++) {
    std::cin >> p[i];
  }
  std::vector<long long> q(B);
  for (int i = 0; i < B; i++) {
    std::cin >> q[i];
  }
  std::vector<long long> r(C);
  for (int i = 0; i < C; i++) {
    std::cin >> r[i];
  }
  solve(X, Y, A, B, C, std::move(p), std::move(q), std::move(r));
  return 0;
}
