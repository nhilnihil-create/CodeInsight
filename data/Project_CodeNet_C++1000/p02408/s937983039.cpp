#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  // row: S, H, C, D
  bool a[4][13] = {false};

  char kind;
  int v;
  for (int i = 0; i < n; ++i) {
    cin >> kind >> v;
    switch (kind) {
      case 'S':
        a[0][v-1] = true;
        break;
      case 'H':
        a[1][v-1] = true;
        break;
      case 'C':
        a[2][v-1] = true;
        break;
      case 'D':
        a[3][v-1] = true;
        break;
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 13; ++j) {
      if (!a[i][j]) {
        if (i == 0) printf("S");
        else if (i == 1) printf("H");
        else if (i == 2) printf("C");
        else printf("D");

        printf(" %d\n", j + 1);
      }
    }
  }

  return 0;
}