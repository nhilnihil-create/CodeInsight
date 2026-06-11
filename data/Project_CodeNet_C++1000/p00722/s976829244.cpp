#include <bits/stdc++.h>
using namespace std;

int T, D, N;
bool is_composite[1145142];

int main() {
  is_composite[1] = true;
  for (int i=2; i<=1145141; i++) {
    if (!is_composite[i]) {
      for (int j=i+i; j<=1145141; j+=i) {
        is_composite[j] = true;
      }
    }
  }
  
  while (1) {
    scanf("%d%d%d", &T, &D, &N);
    if ((T|D|N) == 0) return 0;

    int cnt = 0;
    int t = T;
    while (1) {
      if (!is_composite[t]) cnt++;
      if (cnt == N) break;
      t += D;
    }
    printf("%d\n", t);
  }
}
  