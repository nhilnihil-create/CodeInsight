#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int x, y, s;
  while (true) {
    scanf("%d %d %d", &x, &y, &s);
    if (x == 0 && y == 0 && s == 0) break;
    int max_sum = 0;
    for (int c1=1;c1<=s/2;c1++) {
      const int c2x = s-c1*(100+x)/100;
      if (c2x <= 0) continue;
      int c2 = c2x*100/(100+x);
      while (c2*(100+x)/100 < c2x) c2++;
      if (c2*(100+x)/100 != c2x) continue;
      if (c2 < 1 || c2 > s-1) continue;
      max_sum = max(max_sum, c1*(100+y)/100+c2*(100+y)/100);
    }
    printf("%d\n", max_sum);
  }
  return 0;
}