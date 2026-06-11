#include <bits/stdc++.h>
using namespace std;

int main() {
  long x;
  cin >> x;
  for (long i = -1000; i <= 1000; ++i) {
    for (long j = -1000; j <= 1000; ++j) {
      long a = i * i * i * i * i - j * j * j * j * j;
      if (a == x) {
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  }
}