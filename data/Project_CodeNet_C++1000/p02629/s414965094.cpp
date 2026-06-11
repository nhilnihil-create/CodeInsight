#include <iostream>
#include <cmath>

using namespace std;

int main() {
  string alphabets = "abcdefghijklmnopqrstuvwxyz", ans;
  unsigned long long n, q;
  cin >> n;
  
  while (n--) {
    ans = alphabets[n % 26] + ans;
    n /= 26;
  }
  
  cout << ans;
  
  return 0;
}