#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  N %= 10;
  if (N == 3) return cout << "bon" << "\n", 0;
  if (N == 0) return cout << "pon" << "\n", 0;
  if (N == 1) return cout << "pon" << "\n", 0;
  if (N == 6) return cout << "pon" << "\n", 0;
  if (N == 8) return cout << "pon" << "\n", 0;
  cout << "hon" << "\n";
}