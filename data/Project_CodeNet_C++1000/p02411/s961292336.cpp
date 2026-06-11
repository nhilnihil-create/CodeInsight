#include <cstdio>
#include <iostream>

using namespace std;

inline void grade(int sum, int l, int h, char c) {
  if (sum >= l && sum < h) {
    printf("%c\n", c);
  }
}

int main() {
  int m, f, r;
  for (;;) {
    cin >> m >> f >> r;
    if (m == -1 && f == -1 && r == -1) {
      break;
    }

    const int sum = m + f;
    if (m == -1 || f == -1 || sum < 30) {
      printf("F\n");
      continue;
    }

    if (sum >= 30 && sum < 50) {
      if (r >= 50) {
        printf("C\n");
      } else {
        printf("D\n");
      }
    }
    grade(sum, 50, 65, 'C');
    grade(sum, 65, 80, 'B');
    grade(sum, 80, 201, 'A');
  }

  return 0;
}