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

long long int n, a, b;

template <typename T> class Mod {
  T m;
  T __swap(T *a, T *b) {
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

long long int func1(long long int n) {
  long long int tmp = 1;
  long long int nino_1000 = 1;

  // 10^3を求める
  for (long long int i = 1; i <= 1000; i++) {
    nino_1000 = md.mul(nino_1000, 2);
  }
  // 10^nを求める
  for (long long int i = 1; i <= n / 1000; i++) {
    tmp = md.mul(tmp, nino_1000);
  }
  for (long long int i = 1; i <= n % 1000; i++) {
    tmp = md.mul(tmp, 2);
  }
  tmp = tmp - 1;

  return tmp;  
}

long long int func2(long long int n, long long int a) {
  long long int tmp = 1;

  for (long long int i = n; i >= n - a + 1; i--) {
    tmp = md.mul(tmp, i);
  }
  for (long long int i = 1; i <= a; i++) {
    tmp = md.div(tmp, i);
  }

  return tmp;
}

long long int ans = 0, t1 = 0, t2 = 0, t3 = 0;

int main() {
  std::cin >> n >> a >> b;

  t1 = func1(n);
  t2 = func2(n, a);
  t3 = func2(n, b);

  ans = md.minus(t1, t2);
  ans = md.minus(ans, t3);

  std::cout << ans << std::endl;

  return 0;
}