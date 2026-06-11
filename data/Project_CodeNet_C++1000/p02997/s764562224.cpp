#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  int l = (n - 1) * (n - 2) / 2;
  if (l < k) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << (n - 1) + l - k << endl;
    for (int i = 2; i <= n; i++) cout << 1 << " " << i << endl;

    for (int i = 2; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (l == k)
          return 0;
        else {
          cout << i << " " << j << endl;
          l--;
        }
      }
    }
  }
}