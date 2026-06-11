#include <iostream>

using namespace std;


int gcd(int x, int y) {
  int mod = x % y;
  if(mod == 0) {
    return y;
  }
  return gcd(y, mod);
}

int main() {
  int K;
  cin >> K;

  long total = 0;
  for(int i = 1; i <= K; i++) {
    for(int j = 1; j <= K; j++) {
      for(int k = 1; k <= K; k++) {
        total += gcd(gcd(i, j), k);
      }
    }
  }

  cout << total;

  return 0;
}

