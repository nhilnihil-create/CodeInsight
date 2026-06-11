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

void solve(long long N, long long K, long long R, long long S, long long P,
           std::string T)
{
  

  // dp[i][0] => i回目のじゃんけんでグーを選んだときのその時点での最大得点
  // dp[i][1] => i回目のじゃんけんでチョキを選んだときのその時点での最大得点
  // dp[i][2] => i回目のじゃんけんでパーを選んだときのその時点での最大得点

  ll ret = 0;
  rep(k,K){
    ll i = k;
    vector<vector<ll>> dp(2, vector<ll>(3,0LL));
    int p=0;
    while(i<N){
      char c = T[i];
      if(c=='r'){
        dp[(p+1)%2][0] = max(dp[p%2][1], dp[p%2][2]);
        dp[(p+1)%2][1] = max(dp[p%2][0], dp[p%2][2]);
        dp[(p+1)%2][2] = max(dp[p%2][0], dp[p%2][1])+P;
      }
      if(c=='s'){
        dp[(p+1)%2][0] = max(dp[p%2][1], dp[p%2][2])+R;
        dp[(p+1)%2][1] = max(dp[p%2][0], dp[p%2][2]);
        dp[(p+1)%2][2] = max(dp[p%2][0], dp[p%2][1]);
      }
      if(c=='p'){
        dp[(p+1)%2][0] = max(dp[p%2][1], dp[p%2][2]);
        dp[(p+1)%2][1] = max(dp[p%2][0], dp[p%2][2])+S;
        dp[(p+1)%2][2] = max(dp[p%2][0], dp[p%2][1]);
      }
      p++; i+= K;
    }
    ret += max(dp[p%2]).first;
  }
  cout << ret << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); // Magic for faster cin
  long long N;
  long long K;
  long long R;
  long long S;
  long long P;
  cin >> N>>K>>R>>S>>P;
  std::string T;
  std::cin >> T;
  solve(N, K, R, S, P, T);
  return 0;
}
