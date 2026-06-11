// [[ABC134C] Exception Handling] https://www.luogu.com.cn/problem/AT4843
#include <algorithm>
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
    printf("%d\n", b == 31 ? 1 : 0);
  } else if (a == 4 || a == 6 || a == 9 || a == 11) {
    printf("%d\n", b == 30 ? 1 : 0);
  } else {
    printf("%d\n", b == 28 ? 1 : 0);
  }
  return 0;
}
