#include <iostream>

using namespace std;

bool is_prime(int x) {
  if (x == 2) return true;
  if (x < 2 || x % 2 == 0) return false;

  for (int i = 3; i*i <= x; i += 2)
    if (x % i == 0) return false;

  return true;
}

int main() {
  int ans = 0, n; cin >> n;

  while(n--) {
    int x; cin >> x;
    if (is_prime(x)) ans++;
  }

  cout << ans << endl;
}