/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int64_t GreatestCommonDivisor(const int64_t a, const int64_t b) {
  // GCD. O(log(min(a, b))). 最大公約数.
  int64_t result = -1LL;
  if (a < 0) {
    std::cerr << "ERROR: GreatestCommonDivisor(): a is out of range: " << a << std::endl;
    throw 1;
  } else if (b < 0LL) {
    std::cerr << "ERROR: GreatestCommonDivisor(): b is out of range: " << b << std::endl;
    throw 1;
  } else if (a == 0LL) {
    result = b;
  } else if (b == 0LL) {
    result = a;
  } else {
    const int64_t new_a = std::min(a, b);
    const int64_t new_b = std::max(a, b) % new_a;  // Euclidean Algorithm
    result = GreatestCommonDivisor(new_a, new_b);
  }
  return result;
}

int64_t LeastCommonMultiple(const int64_t a, const int64_t b) {
  // LCM. O(log(min(a, b))). 最小公倍数.
  int64_t result;
  if (a == 0 || b == 0) {
    return 0;
  } else if (a == 1) {
    return b;
  } else if (b == 1) {
    return a;
  } else if (a < 0 || b < 0) {
    std::cerr << "ERROR: LeastCommonMultiple(): Invalid arg. a=" << a << ", b=" << b << std::endl;
    throw 1;
  }
  try {
    result = (a / GreatestCommonDivisor(a, b) * b);
  } catch (...) {
    std::cerr << "ERROR: LeastCommonMultiple()" << std::endl;
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t A, B, C, D;
  cin >> A >> B >> C >> D;
  const int64_t cd = LeastCommonMultiple(C, D);
  // const int64_t L = static_cast<int64_t>(T.length());
  const int64_t wareru = (B / C - (A - 1) / C) + (B / D - (A - 1) / D) - (B / cd - (A - 1) / cd);
  const int64_t result = B - (A - 1) - wareru;
  cout << result << endl;
  return 0;
}
