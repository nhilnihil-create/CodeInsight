#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);

  long long res = 1;
  for (int i = 0; i < n; ++i) {
    if (res == 0) break;
    if (a[i] > 1000000000000000000 / res) {
      cout << -1 << endl;
      return 0;
    }
    
    res *= a[i];
  }

  cout << res << endl;
}
