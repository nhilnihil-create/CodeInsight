#include <iostream>
#include <vector>

int lcm(int x, int y)
{
  int cand[] = {2, 3};
  int lcm = 1;

  do {
    bool flag = false;
    int factor = cand[0];

    if(x % factor == 0) {
      x /= factor;
      flag = true;
    }
    if(y % factor == 0) {
      y /= factor;
      flag = true;
    }

    if(flag) {
      lcm *= factor;
      continue;
    }

    cand[0] = cand[1];
    cand[1] += 2;
  } while (x != 1 || y != 1);

  return lcm;
}

int main() {
  int X, ans;
  std::cin >> X;

  ans = lcm(360, X) / X;
  std::cout << ans << std::endl;
  return 0;
}
