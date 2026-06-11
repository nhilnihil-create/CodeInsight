#include <iostream>

using namespace std;

int main() {

  long long n, m, k;
  cin >> n >> m >> k;
  cout << max(n-k, 0LL) << ' ' << max(0LL, m + min(0LL, n - k));
  return 0;
}
