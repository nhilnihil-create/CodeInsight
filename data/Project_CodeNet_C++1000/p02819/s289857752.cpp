#include <bits/stdc++.h>
using namespace std;

bool isp(int n) {
  if (n < 2) return false;
  else if (n == 2) return true;
  else if (n % 2 == 0) return false;
  for (int i = 3; i <= (int) sqrt(n); i += 2) if (n % i == 0) return false;
  return true;
}

int main() {
  int N;
  cin >> N;
  while (true) {
    if (isp(N)) return cout << N << "\n", 0;
    N++;
  }
}