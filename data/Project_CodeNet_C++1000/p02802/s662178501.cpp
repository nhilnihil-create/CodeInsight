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

void solve(long long N, long long M, std::vector<long long> p,
           std::vector<std::string> S) 
{
  vector<bool> aced(N,false);
  vector<int> cnt(N,0); int ac=0;
  rep(i,M){
    if(S[i]=="AC"){
      if(!aced[p[i]-1]) { aced[p[i]-1] = true; ac++; }
    }
    else if(S[i]=="WA"){
      if(!aced[p[i]-1]) cnt[p[i]-1]++;
    }
  }
  int ret = 0;
  rep(i,N){
    if(aced[i]) ret += cnt[i];
  }
  cout << ac << " " << ret << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); // Magic for faster cin
  long long N;
  std::cin >> N;
  long long M;
  std::cin >> M;
  std::vector<long long> p(M);
  std::vector<std::string> S(M);
  for (int i = 0; i < M; i++) {
    std::cin >> p[i];
    std::cin >> S[i];
  }
  solve(N, M, std::move(p), std::move(S));
  return 0;
}
