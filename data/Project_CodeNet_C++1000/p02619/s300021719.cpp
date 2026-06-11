// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
// DEBUG {{{
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <valarray>
#include <vector>
template < int n, class... T >
typename std::enable_if< (n >= sizeof...(T)) >::type __output_tuple(
    std::ostream &, std::tuple< T... > const &) {}
template < int n, class... T >
typename std::enable_if< (n < sizeof...(T)) >::type __output_tuple(
    std::ostream &os, std::tuple< T... > const &t) {
  os << (n == 0 ? "" : ", ") << std::get< n >(t);
  __output_tuple< n + 1 >(os, t);
}
template < class... T >
std::ostream &operator<<(std::ostream &os, std::tuple< T... > const &t) {
  os << "(";
  __output_tuple< 0 >(os, t);
  os << ")";
  return os;
}
template < class T, class U >
std::ostream &operator<<(std::ostream &os, std::pair< T, U > const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template < class T >
std::ostream &operator<<(std::ostream &os, const std::stack< T > &a) {
  os << "{";
  for(auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template < class T, class Container, class Compare >
std::ostream &operator<<(std::ostream &os,
    std::priority_queue< T, Container, Compare > a) {
  os << "{ (top) ";
  while(a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template < class T, class Container >
std::ostream &operator<<(std::ostream &os, std::queue< T, Container > a) {
  os << "{ ";
  while(a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
#ifdef DEBUG
#if !defined(DEBUG_OUT)
#define DEBUG_OUT std::cerr
#endif
#define dump(...)                                                                \
  [&]() {                                                                        \
    auto __debug_tap = std::make_tuple(__VA_ARGS__);                             \
    DEBUG_OUT << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = " << __debug_tap \
    << std::endl;                                                      \
  }()
template < class T >
inline void dump2D(T &d, size_t sizey, size_t sizex) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << "\t";
    for(size_t j = 0; j < sizex; j++)
      DEBUG_OUT << d[i][j] << (j + 1 == sizex ? "" : "\t");
    DEBUG_OUT << std::endl;
  }
}
template < class T >
inline void dump1D(T &d, size_t sizey) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << d[i] << (i + 1 == sizey ? "" : " ");
  }
  DEBUG_OUT << std::endl;
}
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        os << "{";
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : ", ") << *ite;
        os << "}";
        return os;
      }
#else
#define dump(...) ((void) 42)
#define dump2D(...) ((void) 42)
#define dump1D(...) ((void) 42)
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : " ") << *ite;
        return os;
      }
#endif
// }}}

constexpr int D = 365;
constexpr int K = 26;
int c[400];
int s[400][26];
random_device rnd;
mt19937 mt(rnd());
constexpr ll inf = 4e9;

using Ans = array<int, D>;
using IScore = double;
using PScore = double;
pair<Ans, IScore> solve(bool r) {
  Ans res;
  PScore f[K] = {};
  ll act[K] = {};
  IScore score = 0;
  for(int i = 0; i < D; i++) {
    for(int j = 0; j < K; j++) act[j] += act[j] + c[j];
    if(r) {
      for(int j = 0; j < K; j++) f[j] += f[j] + c[j];
    } else {
      for(int j = 0; j < K; j++) f[j] += (f[j] + c[j]) * (1.0 + (((int(mt() % 101) - 50) / 100.0) / 5));
    }

    using P = pair<IScore, int>;
    P best(-1, -1);
    for(int j = 0; j < K; j++) best = max(best, P(f[j] + s[i][j], j));

    int chosen = best.second;
    score += s[i][chosen] + act[chosen];
    f[chosen] = 0;
    act[chosen] = 0;
    res[i] = chosen;

  }
  return {res, score};
}

void output(Ans ans) {
  for(int i = 0; i < D; i++) {
    cout << ans[i] + 1 << "\n";
  }
}

int _D;
void input() {
  cin >> _D;
  for(int i = 0; i < K; i++) cin >> c[i];
  for(int i = 0; i < _D; i++)
    for(int j = 0; j < K; j++) {
      cin >> s[i][j];
    }
}

ll calc(Ans ans) {
  ll x[K] = {};
  ll res = 0;
  for(int i = 0; i < D; i++) {
    for(int j = 0; j < K; j++) {
      x[j] += c[j];
      if(j == ans[i]) x[j] = 0;
      res -= x[j];
    }
    dump(ans[i]);
    res += s[i][ans[i]];
    cout << res << "\n";
  }
  res += ll(1e6);
  return res;
}

Ans ioutput() {
  Ans ans;
  for(int i = 0; i < D; i++) {
    if(i < _D) cin >> ans[i], ans[i]--;
    else ans[i] = 0;
  }
  dump(ans);
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  input();
  auto ans = ioutput();
  auto score_a = calc(ans);
  dump(score_a);
  // 2000 / 20 = 100
  // pair<Ans, IScore> best;
  // for(int i = 0; i < 100; i++) {
  //   dump(i);
  //   auto [ans, score] = solve(i > 0);
  //   dump(score);
  //   if(best.second < score) {
  //     best = {ans, score};
  //   }
  // }
  // output(best.first);
  // dump(best.second);
  return 0;
}
