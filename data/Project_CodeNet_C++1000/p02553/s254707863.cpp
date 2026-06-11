#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  printf("%lld", max(max(a*c, a*d), max(b*c, b*d)));
  return 0; 
}