/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

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

std::vector<std::pair<int64_t, int64_t>> FactorizeIntoPrimeFactors(const int64_t N) {
  std::vector<std::pair<int64_t, int64_t>> result;
  if (N <= 0LL || N == 1LL) {
    return result;
  }
  int64_t remaining = N;
  for (int64_t i = 2LL; i * i <= remaining; ++i) {
    int64_t count = 0LL;
    while (remaining % i == 0LL) {
      ++count;
      remaining /= i;
    }
    if (count > 0LL) {
      result.push_back(std::pair<int64_t, int64_t>(i, count));
    }
  }
  if (remaining > 1) {
    result.push_back(std::pair<int64_t, int64_t>(remaining, 1));
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t A, B;
  cin >> A >> B;
  const int64_t gcd = GreatestCommonDivisor(A, B);
  vector<Pair> fs = FactorizeIntoPrimeFactors(gcd);
  int64_t result = 1;
  result += static_cast<int64_t>(fs.size());
  cout << result << endl;
  return 0;
}
