#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <ios>
#include <iomanip>

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

char i2c(int i)
{
  return char('a' + i);
}


int main()
{
  uint64_t N;
  std::cin >> N;

  const uint64_t n = 26;
  uint64_t i=1; // i-place number(i=3, aaa-zzz)
  while(N - std::pow(n, i) > 0) {
    N -= std::pow(n, i);
    i++;
  }

  // let N 0 origin
  N--;

  auto ary26 = n_ary(N, n);
  // print_container(ary26, "ary26");

  // i=3, ary26 = {1, 2} => s = abc
  std::string s;
  for(auto k: ary26) {
    s = s + i2c(k);
  }

  std::cout << std::setw(i) << std::setfill('a')
            << s << std::endl;

  return 0;
}
