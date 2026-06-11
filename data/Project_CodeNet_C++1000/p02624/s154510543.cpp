#include <iostream>
#include <vector>
using namespace std;

long long f(long long n) {
  long long res = (n * (n + 1)) / 2;
  return res;
}

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * f(n/i);
  }
  
  cout << ans;
}