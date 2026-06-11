#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c) {
  int x;
  x = min(a, b);
  x = min(x, c);
  return x;
}

int main() {
  int k;
  cin >> k;
  int gcd = 1, sum = 0;
  for(int a = 1; a <= k; a++) {
    for(int b = 1; b <= k; b++) {
      for(int c = 1; c <= k; c++) {
        for(int i = 2; i <= min(a, b, c); i++) {
          if(a % i == 0 && b % i == 0 && c % i == 0) gcd = i;
        }
        sum += gcd;
        gcd = 1;
      }
    }
  }
  cout << sum << endl;
}