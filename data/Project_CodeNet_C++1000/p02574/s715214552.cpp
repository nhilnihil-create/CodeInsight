#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <chrono>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

template<typename T> using maximum_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template<typename T> using minimum_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
std::istream& operator>>(std::istream &is, std::vector<T> &v)
{
  for (typename std::vector<T>::size_type i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}

namespace IntegerMath
{
  int64_t floor_div(int64_t x, int64_t y) {
    return x / y;
  }

  int64_t ceil_div(int64_t x, int64_t y) {
    return (x / y) + std::min(static_cast<int64_t>(1), x % y);
  }

  int64_t sqrt(int64_t x) {
    return static_cast<int64_t>(
      ::floorl( ::sqrtl( 
        static_cast<long double>(x)
      ) )
    );
  }

  int64_t log2(int64_t x) {
    return static_cast<int64_t>(
      ::floorl( ::log2l( 
        static_cast<long double>(x)
      ) )
    );
  }    

  int64_t log10(int64_t x) {
    return static_cast<int64_t>(
      ::floorl( ::log10l( 
        static_cast<long double>(x)
      ) )
    );
  }

  int64_t number_of_digits(int64_t x) {
    return static_cast<int64_t>(
      ::ceill( ::log10l( 
        static_cast<long double>(x + 1)
      ) )
    );
  }

  uint64_t gcd(uint64_t a, uint64_t b)
  {
    uint64_t n = std::min(a, b), m = std::max(a, b);
    return (n == 0) ? m : gcd(m % n, n);
  }

  uint64_t lcm(uint64_t a, uint64_t b)
  {
    uint64_t d = gcd(a, b);
    return (a % d == 0) ? (a / d) * b : a * (b / d);
  }
};

class Prime
{
private:
  std::set<uint64_t> _primes;

  bool _is_prmie(uint64_t n) const {
    uint64_t m = IntegerMath::sqrt(n);
    for (uint64_t d : _primes) {
      if (n % d == 0) { return false; }
      if (d > m) { break; }
    }
    return true;
  }

public:
  Prime(uint64_t n) {
    _primes.insert(2);

    for (uint64_t i = 3; i <= n; i += 2) {
      if (_is_prmie(i)) {
        _primes.insert(i);
      }
    }
  }

  std::set<uint64_t> set() const { return _primes; }
};

using namespace std;

int main()
{
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N);
  cin >> A;

  uint64_t set_gcd = A[0], count_one = 0;
  set<uint64_t> B;
  N_TIMES(n, N) {
    set_gcd = gcd(set_gcd, A[n]);
    if (A[n] == 1) { ++count_one; }
    B.insert(A[n]);
  }

  const Prime prime(1e+3 + 10);
  const set<uint64_t> prime_set = prime.set();
  map<uint64_t, uint64_t> counter;
  bool pairwise_flag = true;
  N_TIMES(n, N) {
    uint64_t an = A[n];
    map<uint64_t, uint64_t> an_factor;
    for (uint64_t p : prime_set) {
      if (an % p == 0) {
        ++an_factor[p];
        while (an > 1 && an % p == 0) { an /= p; }
      }
    }
    if (an != 1) { ++an_factor[an]; }

    for (const auto &ps : an_factor) {
      if (counter[ps.first] > 0) {
        pairwise_flag = false;
        break;
      } else {
        counter[ps.first] += ps.second;
      }
    }

    if (!pairwise_flag) { break; }
  }

  if (pairwise_flag) {
    cout << "pairwise coprime" << endl;
  } else if (set_gcd == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }

  return 0;
}