#include <bits/stdc++.h>
using namespace std;

int main() {
  int S, W;
  scanf("%d %d", &S, &W);
  if (S <= W) {
    puts("unsafe");
  } else {
    puts("safe");
  }
}
