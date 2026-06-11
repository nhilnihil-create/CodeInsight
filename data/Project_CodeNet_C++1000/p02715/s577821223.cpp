#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

template <int64_t MOD>
class Modint {
  using Self = Modint<MOD>;

  int64_t m_value;

 public:
  Modint(int64_t value) : m_value((value % MOD + MOD) % MOD) {}
  Self pow(int64_t e) const {
    if (e == 0) {
      return (Self)1;
    } else if (e % 2 == 0) {
      return ((*this) * (*this)).pow(e / 2);
    } else {
      return (*this).pow(e - 1) * (*this);
    }
  }
  Self inv() const { return pow(MOD - 2); }
  Self& operator=(const Self& rh) {
    m_value = rh.m_value;
    return *this;
  }
  Self operator-() const { return Self(-m_value); }
  Self operator+(const Self& other) const {
    return Self(m_value + other.m_value);
  }
  Self operator-(const Self& other) const {
    return Self(m_value - other.m_value);
  }
  Self operator*(const Self& other) const {
    return Self(m_value * other.m_value);
  }
  Self operator/(const Self& other) const { return (*this) * other.inv(); }
  Self& operator+=(const Self& rh) { return (*this) = (*this) + rh; }
  Self& operator-=(const Self& rh) { return (*this) = (*this) - rh; }
  Self& operator*=(const Self& rh) { return (*this) = (*this) * rh; }
  int64_t value() const { return m_value; }
};

int main() {
  int N, K;
  cin >> N >> K;

  using Mint = Modint<1'000'000'007>;
  vector<Mint> dp(K + 1, 0);
  Mint result = 0;
  for (int d = K; d >= 1; d--) {
    dp[d] = Mint(K / d).pow(N);
    for (int j = 2 * d; j <= K; j += d) {
      dp[d] -= dp[j];
    }
    result += dp[d] * d;
  }
  cout << result.value() << endl;

  return 0;
}