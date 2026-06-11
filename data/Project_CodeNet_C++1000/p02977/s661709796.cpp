#include <iostream>
#include <vector>

using namespace std;

int power_of_two (int x) {
  while (x % 2 == 0) x /= 2;
  return x == 1;
}

const int MAX_N = 2e5 + 5;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  if (power_of_two(n)) {
    cout << "No" << endl;
    exit(0);
  }

  cout << "Yes" << '\n';
  cout << 1 << " " << 2 << '\n';
  cout << 2 << " " << 3 << '\n';
  cout << 1 << " " << n + 3 << '\n';
  cout << n + 3 << " " << n + 2 << '\n';
  cout << n + 2 << " " << n + 1 << '\n';
  for (int i = 4; i + 1 <= n; i += 2) {
    int u = i;
    int v = i + 1;

    cout << 1 << " " << u << '\n';
    cout << u << " " << v << '\n';
    cout << 1 << " " << n + v << '\n';
    cout << n + v << " " << n + u << '\n';
  }

  if (n % 2 == 0) {
    int p = n & -n;
    int q = n + n - p;

    cout << n << " " << p << '\n';
    cout << n + n << " " << q + 1 << '\n';
  }
}
