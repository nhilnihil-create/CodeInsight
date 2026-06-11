#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <utility>
#include <boost/foreach.hpp>
#include <cmath>

template <typename T> class Mod {
  T m;
  void __swap(T *a, T *b) {
    T tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
  }
  T __modinv(T a) {
    T b = m, u = 1, v = 0;
    while (b) {
      T t = a / b;
      a -= t * b; __swap(&a, &b);
      u -= t * v; __swap(&u, &v);
    }
    u %= m;
    if (u < 0) {
      u += m;
    }
    return u;
  }
public:
  Mod(T param) {
    m = param;
  }
  T plus(T a, T b) {
    // O(1)
    a %= m;
    b %= m;
    return (a + b) % m;
  }
  T minus(T a, T b) {
    // O(1)
    T ret;
    a %= m;
    b %= m;
    ret = a - b;
    if (ret < 0) {
      return ret + m;
    }
    return ret;
  }
  T mul(T a, T b) {
    // O(1)
    a %= m;
    b %= m;
    return (a * b) % m;
  }
  T div(T a, T b) {
    // O( max(log(a), log(b)) ) (?)
    T ret;

    a = a % m;
    ret = a * __modinv(b) % m;

    return ret;
  }
};

Mod<long long int> md(1000000000 + 7);
long long int x, y, ans = 0;

void func2(long long int pat1, long long int pat2);

void func1(long long int X, long long int Y) {
  long long int pat1, pat2;

  pat1 = X / 2;  
  if (X - (pat1 * 2) == 1) {
    pat2 = 1;
  }
  else {
    pat2 = 0;
  }

  for (; 0 <= pat1; pat1--, pat2 += 2) {
    if ((pat1 * 2 + pat2 * 1 == X) && (pat1 * 1 + pat2 * 2 == Y)) {
      // TODO
      func2(pat1, pat2);
    }
  }
}

void func2(long long int pat1, long long int pat2) {
  long long int tmp = 1;

  for (long long int i = (pat1 + pat2); i >= (pat1 + pat2 - pat1 + 1); i--) {
    tmp = md.mul(tmp, i);
  }
  for (long long int i = 1; i <= pat1; i++) {
    tmp = md.div(tmp, i);
  }

  ans = tmp;
}

int main() {
  std::cin >> x >> y;

  func1(x, y);

  std::cout << ans << std::endl;

  return 0;
}