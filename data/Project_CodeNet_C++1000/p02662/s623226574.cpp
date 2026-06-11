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
  explicit Modint(int64_t value) : m_value((value % MOD + MOD) % MOD) {}
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
  using Mint = Modint<998244353L>;

  int N, S;
  cin >> N >> S;

  vector<vector<Mint>> dp(N + 1, vector<Mint>(S + 1, (Mint)0));
  const Mint u = Mint(2).pow(N);
  const Mint i2 = Mint(2).inv();
  dp[0][0] = u;

  rep(i, N) {
    int a;
    cin >> a;
    irep(j, S) {
      if (j == 0) {
        dp[i + 1][j] = u;
      } else {
        dp[i + 1][j] = dp[i][j];
        if (j - a >= 0) {
          dp[i + 1][j] += dp[i][j - a] * i2;
        }
      }
    }
  }

  cout << dp[N][S].value() << endl;

  return 0;
}