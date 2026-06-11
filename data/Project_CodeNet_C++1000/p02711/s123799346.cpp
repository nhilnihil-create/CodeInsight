#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  while (N) {
    if (N % 10 == 7) return cout << "Yes" << "\n", 0;
    N /= 10;
  }
  cout << "No" << "\n";
}