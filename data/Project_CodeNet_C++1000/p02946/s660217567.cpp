#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int k, x;
  cin >> k >> x;
  for (int n = x - k + 1; n <= x + k - 1; n++) {
    cout << n << ' ';
  }

  cout << endl;
  return 0;
}
