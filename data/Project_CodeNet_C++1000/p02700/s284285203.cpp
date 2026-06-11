#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  while (true) {
    C -= B;
    if (C <= 0) return cout << "Yes" << "\n", 0;
    A -= D;
    if (A <= 0) return cout << "No" << "\n", 0;
  }
}