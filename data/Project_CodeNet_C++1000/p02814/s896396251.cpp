#include <iostream>
#include <algorithm>
#include <vector>

uint64_t get_GCD(uint64_t lhs, uint64_t rhs)
{
  uint64_t a = std::max(lhs, rhs);
  uint64_t b = std::min(lhs, rhs);

  if(b == 0) return 1;

  uint64_t res = a % b;

  while(res != 0) {
    a = b;
    b = res;
    res = a % b;
  }
  return b;
}

uint64_t get_LCM(uint64_t lhs, uint64_t rhs) {
  uint64_t gcd = get_GCD(lhs, rhs);
  return (lhs * rhs) / gcd;
}

// check lhs, rhs have semi common multiple
// \param lhs, rhs even number
bool has_scm(uint64_t lhs, uint64_t rhs) {
  // a * m - b * n = (b-a)/2
  // so (b-a)/2 must be multiple of gcd(a,b)

  uint64_t a = std::max(lhs, rhs);
  uint64_t b = std::min(lhs, rhs);

  uint64_t gcd_ab = get_GCD(a, b);

  return ((a-b)/2) % gcd_ab == 0;
}

int main()
{
  uint64_t N, M;
  std::cin >> N >> M;

  std::vector<uint64_t> a(N);
  for(uint64_t i=0; i<N; i++) {
    std::cin >> a[i];
  }

  // if two numbers a, b has scm, then
  // they are integrated with semi multiples of lcm(a, b)
  uint64_t x = a[0];
  for(uint64_t i=1; i<N; i++) {
    if(has_scm(x, a[i])) {
      uint64_t xx = get_LCM(x, a[i]);
      // avoid overflow
      if(xx < x || xx/2 > M) {
        x = 0;
        break;
      }
      x = xx;
      // std::cout << "i: " << i << " x: " << x << std::endl;
    } else {
      x = 0;
      break;
    }
  }
  // std::cout << "x: " << x << std::endl;

  uint64_t ret = 0;
  if(x !=0) {
    while(x/2 + x * ret <= M) {
      ret++;
    }
  }

  std::cout << std::fixed << ret << std::endl;
  // std::cout << ret << std::endl;
  return 0;
}
