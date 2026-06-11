#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long y = n / i;
    ans += y * (y + 1) * i / 2;
  }
  cout << ans << endl;
}
