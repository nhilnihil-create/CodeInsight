#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>

using PrimeFactorization = std::map<uint64_t, uint64_t>;

template <typename Map ,class T>
bool contains_map(const Map &c, const T &v)
{
  return c.find(v) != c.end();
}

template <typename Map>
void print_map(const Map &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.begin(), c.end(),
                [](auto &x) { std::cout << x.first << "->" << x.second << ", "; });
  std::cout << std::endl;
}

template <typename Map ,class T>
bool contains(const Map &c, const T &v)
{
  return c.find(v) != c.end();
}

PrimeFactorization prime_factorization(uint64_t v)
{
  PrimeFactorization ret;
  ret[1] = 1;
  uint64_t div = 2;
  uint64_t fin = std::sqrt(v) + 1;
  while(div<fin) {
    if(v % div != 0) {
      div++;
      continue;
    }
    ret[div]++;
    v /= div;
    if(v == 1) {
      break;
    }
  }
  if(v != 1) {
    ret[v]++;
  }

  return ret;
}

int main()
{
  uint64_t A, B;
  std::cin >> A >> B;

  auto pf_a = prime_factorization(A);
  auto pf_b = prime_factorization(B);
  // print_map(pf_a, "pf_a");
  // print_map(pf_b, "pf_b");

  uint64_t ret = 0;
  for(auto p: pf_a) {
    auto k = p.first;
    if(contains(pf_b, k)) {
      ret++;
    }
  }

  std::cout << ret << std::endl;
  return 0;
}

