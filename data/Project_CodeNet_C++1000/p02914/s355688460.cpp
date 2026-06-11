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
// #define DEBUG_OUT std::cerr
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


int n;
ll a[112345];
ll b[112345];

// return ( values, isSolvable, rank )
// return 0-length vector when unsolvable
/// --- Gaussian Elimination {{{ ///
// using Gauss-Jordan Elimination
#include <cassert>
#include <cmath>
#include <utility>
#include <vector>
template < class T >
void Gauss(vector< vector< T > > &mat) {
  size_t n = mat.size(), m = mat[0].size();
  size_t now = 0;
  for(size_t i = 0; i < m; i++) {
    int pivot = now;
    // pivotting
    for(size_t j = now + 1; j < n; j++) {
      if(mat[pivot][i] != T(0)) break;
      pivot = j;
    }
    if(mat[pivot][i] == T(0)) continue;
    swap(mat[now], mat[pivot]);
    for(size_t j = 0; j < n; j++)
      if(j != now) {
        for(size_t k = 0; k < m; k++) if(k != i) {
          mat[j][k] ^= mat[j][i] & mat[now][k];
        }
        mat[j][i] = 0;
      }
    now++;
    if(now == n) break;
  }
}
/// }}}--- ///



int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n;
  ll sum = 0;
  for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i], sum ^= a[i];
  for(int j = 0; j < 60; j++) if((sum >> j) & 1) {
    for(int i = 0; i < n; i++) if((b[i] >> j) & 1) b[i] = b[i] ^ (1ll << j);
  }

  vector<vector<int>> m(n, vector<int>(60));
  for(int i = 0; i < n; i++) for(int j = 0; j < 60; j++) {
    if((b[i] >> j) & 1) {
      m[i][59-j] = 1;
    }
  }
  dump2D(m, n, 60);
  Gauss(m);
  ll ans = 0;
  for(int i = 0; i < n; i++) for(int j = 0; j < 60; j++) {
    if(m[i][59-j]) ans ^= 1ll << j;
  }

  dump2D(m, n, 60);

  dump(ans);
  dump(2 + 16 + 32 + 64);
  dump(bitset<10>(sum));
  dump(bitset<10>(94));

  cout << (ans << 1) + sum << endl;

  return 0;
}
