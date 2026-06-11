#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  for (register int i=1; i<=179; ++i) {
    if (360*i % n == 0) return cout << 360*i/n, 0;
  }
}