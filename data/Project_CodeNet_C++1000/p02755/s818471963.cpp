#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  for (int i = 1; i <= 100000; i++) {
    bool b = 1;
    if (i * 8 / 100 != A) b = 0;
    if (i * 10 / 100 != B) b = 0;
    if (b) return cout << i << "\n", 0;
  }
  cout << -1 << "\n";
}