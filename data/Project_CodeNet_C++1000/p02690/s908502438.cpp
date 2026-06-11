#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  for (long i = -500; i < 500; i++) {
    for (long j = -500; j < 500; j++) {
      if (i * i * i * i * i - j * j * j * j * j == X) return cout << i << " " << j << "\n", 0;
    }
  }
}