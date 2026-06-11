#include <algorithm>
#include <bitset>
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

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

bool is_prime(int n) {
  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      return false;
    }
  }

  return true;
}

vector<pair<int, int>> factorize(int n) {
  vector<pair<int, int>> result;
  for (int p = 2; p * p <= n; p++) {
    if (is_prime(p)) {
      int cnt = 0;
      while (n % p == 0) {
        n /= p;
        cnt++;
      }
      if (cnt > 0) {
        result.push_back(make_pair(p, cnt));
      }
    }
  }
  if (n != 1) {
    result.push_back(make_pair(n, 1));
  }
  return move(result);
}

int totient(const int n) {
  vector<pair<int, int>> fs = factorize(n);
  int result = n;

  for (auto pa : fs) {
    int p, e;
    tie(p, e) = pa;
    result /= p;
    result *= p - 1;
  }
  return result;
}

const int MOD = 2019;

int64_t dpow(int64_t x, int64_t y) {
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return dpow(x * x % MOD, y / 2);
  } else {
    return x * dpow(x, y - 1) % MOD;
  }
}

int main() {
  string s;
  cin >> s;

  const int M = totient(2019);
  vector<int> dp(2019, 0);
  dp[0]++;
  int shift = 1;
  int r = 0;
  int i10 = dpow(10, M - 1);
  int64_t result = 0;
  rep(i, s.size()) {
    r = r * 10 + (s[i] - '0');
    r %= MOD;
    result += dp[r * shift % MOD]++;
    shift *= i10;
    shift %= MOD;
  }
  cout << result << endl;
  return 0;
}