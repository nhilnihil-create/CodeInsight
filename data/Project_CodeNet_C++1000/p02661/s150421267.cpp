#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; cin >> a[i] >> b[i]; ++i) {
  }
  sort(a, a + n);
  sort(b, b + n);
  if (n % 2 == 0) {
    cout << b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1] + 1;
  } else {
    cout << b[n / 2] - a[n / 2] + 1;
  }
  return 0;
}