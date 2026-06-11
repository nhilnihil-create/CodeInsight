#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  if (n % 2 == 1) {
    cout << 0 << endl;
    return EXIT_SUCCESS;
  }

  ll ans = 0;
  ll b = 10;
  while (b <= 2e18) {
    ans += n / b;
    b *= 5;
  }
  cout << ans << endl;
}