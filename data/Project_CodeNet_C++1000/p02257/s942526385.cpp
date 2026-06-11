#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  double s = sqrt(x);
  for (int i = 3; i <= s; i+=2) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  int n, e;
  int count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> e;
    if (isPrime(e)) count++;
  }
  cout << count << endl;

  return 0;
}