#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <string>
#include <set>
#include <map>

int main() {
  intmax_t t1, t2, a1, a2, b1, b2;
  scanf("%jd %jd %jd %jd %jd %jd", &t1, &t2, &a1, &a2, &b1, &b2);

  if (t1*a1 + t2*a2 == t1*b1 + t2*b2)
    return puts("infinity"), 0;

  if (a1 < b1 || (a1 == b1 && t1*a1 + t2*a2 > t1*b1 + t2*b2)) {
    std::swap(a1, b1);
    std::swap(a2, b2);
  }

  // a1 >= b1
  if (t1*a1 + t2*a2 > t1*b1 + t2*b2)
    return puts("0"), 0;

  intmax_t d = - (t1*a1 + t2*a2) + (t1*b1 + t2*b2);
  intmax_t u = t1*b1 + t2*b2;

  auto f = [&](intmax_t i) -> bool {
             return t1*a1 >= t1*b1 + d*i;
           };

  auto fs = [&](intmax_t i) -> bool {
              return t1*a1 > t1*b1 + d*i;
            };

  intmax_t lb = 0;
  intmax_t ub = (u+d-1)/d + 10;
  while (ub-lb > 1) {
    intmax_t mid = (lb+ub) >> 1;
    (f(mid)? lb: ub) = mid;
  }
  intmax_t res = 2*lb;
  if (fs(lb)) ++res;
  printf("%jd\n", res);
}
