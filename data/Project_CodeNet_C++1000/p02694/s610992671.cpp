#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long x;
  unsigned long long a = 100;
  cin >> x;
  for (unsigned long long i = 0; i < x; i++) {
    a += a/100;
    if (a >= x) {
      cout << i+1 << endl;
      break;
    }
  }
}