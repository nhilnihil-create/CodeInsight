#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

std::vector<int> n_ary(uint64_t decimal, uint64_t base)
{
  uint64_t s = decimal;
  std::vector<int> ret;
  while(s >= base) {
    int r = s % base;
    s /= base;
    ret.push_back(r);
  }
  ret.push_back(s);

  std::reverse(ret.begin(), ret.end());
  return ret;
}

class ModComb {
public:
  /**
   * \param p prime number
   * \param max_table max number for table
   *
   * To calcurate nCk, n < max_table. For example,
   *   mc = ModComb(p, 1000)
   *   mc.combination(500, 100) is OK   (500 < 1000)
   *   mc.combination(10000, 100) is NG (10000 < 1000)
   */
  ModComb(uint64_t p, uint64_t max_table);

  uint64_t factorial(uint64_t n) const;
  uint64_t inverse(uint64_t n) const;
  uint64_t factorial_inverse(uint64_t n) const;

  uint64_t combination(uint64_t n, uint64_t k) const;

  /// (base ^ exp) % p
  uint64_t pow(uint64_t base, uint64_t exp);

private:
  const uint64_t p_, k_;
  // table for n!
  std::vector<uint64_t> factorial_;
  // table for n^(-1)
  std::vector<uint64_t> inverse_;
  // table for (n!)^(-1)
  std::vector<uint64_t> factorial_inverse_;
};

ModComb::ModComb(uint64_t p, uint64_t k)
    : p_(p), k_(k)
{
  if(p < k) {
    throw std::runtime_error("p < k (must k <= p");
  }

  factorial_.resize(k_ + 1);
  inverse_.resize(k_ + 1);
  factorial_inverse_.resize(k_ + 1);

  factorial_[0] = factorial_[1] = 1;
  inverse_[0] = inverse_[1] = 1;
  factorial_inverse_[0] = factorial_inverse_[1] = 1;
  for(uint64_t i=2; i<=k_; i++) {
    factorial_[i] = (i * factorial_[i-1]) % p_;
    int64_t a = - (p_/i) * inverse_[p_ % i];
    while(a<0) {
      a += p_;
    }
    inverse_[i] = a % p_;
    factorial_inverse_[i] = (inverse_[i] * factorial_inverse_[i-1]) % p_;
  }
}

uint64_t ModComb::factorial(uint64_t n) const
{
  if(k_ < n) {
    throw std::runtime_error("too large n (must n <= k)");
  }
  return factorial_[n];
}

uint64_t ModComb::inverse(uint64_t n) const
{
  if(k_ < n) {
    throw std::runtime_error("too large n (must n <= k)");
  }
  return inverse_[n];
}

uint64_t ModComb::factorial_inverse(uint64_t n) const
{
  if(k_ < n) {
    throw std::runtime_error("too large n (must n <= k)");
  }
  return factorial_inverse_[n];
}

uint64_t ModComb::combination(uint64_t n, uint64_t k) const
{
  if(n < k) {
    throw std::runtime_error("error: n < k (must k < n)");
  }
  if(k_ < n) {
    throw std::runtime_error("too large n (must n < k_)"
                             " n = " + std::to_string(n) +
                             " k_ = " + std::to_string(k_));
  }

  return (((factorial_[n] * factorial_inverse_[n-k]) % p_) * factorial_inverse_[k]) % p_;
}

uint64_t ModComb::pow(uint64_t base, uint64_t exp)
{
  // for fast calcuration, calc as following.
  //   ret = base
  //   ret *= ret; // base ** 2
  //   ret *= ret; // base ** 4
  //   ret *= ret; // base ** 8
  //   and so on
  // To avoid remaining loop, we change exp to binary exp,
  // and cache `base ** N` result.
  //
  // ex) base = 3, exp = 10 i.e we want 3**10.
  //  10 = 1010, we calcurate 3^8 and 3^2, then 3^8 * 3^2

  std::vector<int> binexp = n_ary(exp, 2);
  std::reverse(binexp.begin(), binexp.end());
  uint64_t ret = 1;
  uint64_t tmp = base; // base, base^2, base^4, ...

  for(auto i: binexp) {
    tmp *= tmp;
    if(i==1) {
      ret *= tmp;
      ret %= p_;
    }
  }

  return ret;
}


uint64_t pow(uint64_t base, uint64_t exp ,uint64_t p)
{
  std::vector<int> binexp = n_ary(exp, 2);
  std::reverse(binexp.begin(), binexp.end());
  uint64_t ret = 1;
  uint64_t tmp = base; // base, base^2, base^4, ...

  for(auto i: binexp) {
    if(i==1) {
      ret *= tmp;
      ret %= p;
    }
    tmp *= tmp;
    tmp %= p;
  }

  return ret;
}

uint64_t combination(uint64_t n, uint64_t k, uint64_t p, ModComb &mc)
{
  uint64_t ret = 1;

  if(k > n/2) {
    k = n - k;
  }

  for(uint64_t i=0; i<k; i++) {
    ret *= n - i;
    ret %= p;
  }
  ret *= mc.factorial_inverse(k);
  ret %= p;

  return ret;
}

int main()
{
  uint64_t N, a, b;
  std::cin >> N >> a >> b;

  constexpr uint64_t p = std::pow(10, 9) + 7;
  ModComb mc(p, b);

  // By for loop, computational complexity may be too large.
  // So minus comb{n, 0}, comb{n, a}, comb{n, b}
  // from \sum{k=0}{k=n} comb(n, k) = 2^n

  // 2^n
  uint64_t ret = pow(2, N, p);
  // std::cout << "2^" << N << "%" << p << ": " << ret << std::endl;

  // n is too large to calc n!, so calc n*(n-1)*...*(n-a-1) specially

  // minus comb{n, 0}, comb{n, a}, comb{n, b}
  uint64_t tmp = combination(N, 0, p, mc);
  // std::cout << N << "C" << 0 << ": " << tmp << std::endl;
  uint64_t minus = tmp;
  minus %= p;

  tmp = combination(N, a, p, mc);
  // std::cout << N << "C" << a << ": " << tmp << std::endl;
  minus += tmp;
  minus %= p;

  tmp = combination(N, b, p, mc);
  // std::cout << N << "C" << b << ": " << tmp << std::endl;
  minus += tmp;
  minus %= p;

  if(ret < minus) {
    ret += p;
  }

  ret -= minus;
  ret %= p;

  std::cout << ret << std::endl;
  return 0;
}
