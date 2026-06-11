#include <iostream>
using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main() {
  int K;
  cin >> K;
  int ans = 0;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= K; j++) {
      for (int k = 1; k <= K; k++) {
        int a = gcd(gcd(i, j), k);
        ans += a;
      }
    }
  }
  cout << ans << endl; 
}