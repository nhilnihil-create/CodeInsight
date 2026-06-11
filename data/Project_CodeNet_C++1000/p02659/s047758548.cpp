#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  double b;
  cin >> a >> b;
  b = b * 100 + 0.9;
  printf("%lld\n", (a * (long long)b) / 100);
  return 0;
}