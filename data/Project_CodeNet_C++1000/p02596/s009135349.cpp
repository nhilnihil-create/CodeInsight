#include <iostream>
using namespace std;

int pow(int x, int n) {
  if (n == 0) return 1;
  int y = pow(x, n/2);
  int z = y*y;
  if (n & 1) z *= x;
  return z;
}

int main() {
  unsigned long k, l;
  cin >> k;
  
  if (k % 2 == 0 || k % 5 == 0) {
    cout << -1;
    return 0;
  }
  
  unsigned long mod = 0, count = 0;
  do {
    mod = 10*mod + 7;
    mod %= k;
    count++;
  } while (mod);
  
  cout << count;
  
  return 0;
}