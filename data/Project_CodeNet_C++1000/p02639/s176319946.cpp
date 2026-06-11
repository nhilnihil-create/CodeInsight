#include <bits/stdc++.h>

using namespace std;

int main() {
  int x[5];
  for(int i = 0; i < 5; ++i) {
    scanf("%d", x + i);
  }
  for(int i = 0; i < 5; ++i) {
    if(x[i] == 0) {
      printf("%d\n", i + 1);
      break;
    }
  }
  return 0;
}
