#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;

  cin >> x;

  if (x > 3000) {
    cout << 1;
    return 0;
  }

  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 30; j++)
      for (int k = 0; k < 30; k++)
        for (int l = 0; l < 30; l++)
          for (int n = 0; n < 30; n++)
            for (int m = 0; m < 30; m++)
              if (x ==
                  i * 100 + j * 101 + k * 102 + l * 103 + n * 104 + m * 105) {
                cout << 1;
                return 0;
              }

  cout << 0;

  return 0;
}