#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k, s;
  cin >> n >> k >> s;

  int mx = 1000000000;

  if (s < mx) {
    for (int i = 0; i < k; i++) {
      cout << s << endl;
    }
    for (int i = 0; i < n - k; i++) {
      cout << mx << endl;
    }
  } else {
    for (int i = 0; i < k; i++) {
      cout << s << endl;
    }
    for (int i = 0; i < n - k; i++) {
      cout << 1 << endl;
    }
  }

  return 0;
}
