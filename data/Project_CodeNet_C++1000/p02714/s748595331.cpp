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

int rgb123(char rgb){
  switch(rgb){
  case 'R': return 0;
  case 'G': return 1;
  case 'B': return 2;
  }
  return -1;
}


void solve(long long N, std::string S) {
  vec<vec<ll>> cumsum(3, vec<ll>(N+1,0));
  // 色ごとの累積和
  rep(i,N){
    char c = S[i];
    int j = rgb123(c);
    //dump(i,c,j);
    rep(k,3) cumsum[k][i+1] = cumsum[k][i] + (k==j ? 1 : 0);
  }
  //dump(cumsum);
  ll ret = 0;
  rep(i,N){
    int ci = rgb123(S[i]);
    rep(j,i+1,N){
      if(S[i]==S[j]) continue;
      int cj = rgb123(S[j]);
      int col = 3 - ci - cj;  // 色を決定
      ret += cumsum[col][N] - cumsum[col][j+1];
      int k = 2*j-i;
      if(k>=0 && k<N && S[k]!=S[i] && S[k]!=S[j]) ret -= 1LL;
    }
  }
  cout << ret << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); // Magic for faster cin
  cout.precision(12);
  long long N;
  std::cin >> N;
  std::string S;
  std::cin >> S;
  solve(N, S);
  return 0;
}
