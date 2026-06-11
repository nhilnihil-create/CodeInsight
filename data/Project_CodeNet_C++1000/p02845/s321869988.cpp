#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1000000007;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans = 1;
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    if (a[i] == x) { cnt++; }
    if (a[i] == y) { cnt++; }
    if (a[i] == z) { cnt++; }

    ans = (ans * cnt) % mod;

    if (a[i] == x) { x++; }
    else if (a[i] == y) { y++; }
    else if (a[i] == z) { z++; }
  }
  cout << ans << endl;
  return 0;
}