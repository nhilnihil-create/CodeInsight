#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

bool IsPowerOfTwo(int x) {
  return x > 0 && (x & (x - 1)) == 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  if (IsPowerOfTwo(n)) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << 1 << " " << 2 << endl;
  cout << 2 << " " << 3 << endl;
  cout << 3 << " " << n + 1 << endl;
  cout << n + 1 << " " << n + 2 << endl;
  cout << n + 2 << " " << n + 3 << endl;
  for (int i = 4; i + 1 <= n; i += 2) {
    cout << 1 << " " << i << endl;
    cout << i << " " << i + 1 << endl;
    cout << 1 << " " << n + i + 1 << endl;
    cout << n + i + 1 << " " << n + i << endl;
  }

  if (n % 2 == 0) {
    for (int i = 1; i <= n - 1; i++) {
      if ((n ^ i ^ 1) < n) {
        int v1 = i;
        int v2 = n ^ i ^ 1;
        if (v1 == v2) continue;
        if (v1 % 2 == 1) v1 += n;
        if (v2 % 2 == 1) v2 += n;
        cout << n << " " << v1 << endl;
        // cout << v1 << " " << 1 << endl;
        // cout << 1 << " " << v2 << endl;
        cout << v2 << " " << 2 * n << endl;
        return 0;
      }
    }
  }
}
