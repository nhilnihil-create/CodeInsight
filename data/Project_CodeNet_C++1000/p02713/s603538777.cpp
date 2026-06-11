#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int c) {
  int min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  int greatest = 1;
  for (int i = 2; i <= min; i++) {
    if (a%i == 0 && b%i == 0 && c%i == 0) greatest = i;
  }
  return greatest;
}

int main() {
  int k;
  cin >> k;
  
  long ans = 0;
  for (int a = 1; a <= k; a++) {
    for (int b = 1; b <= k; b++) {
      for (int c = 1; c <= k; c++) {
        ans += gcd(a, b, c);
      }
    }
  }
  
  cout << ans;
  
  return 0;
}