#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  int a = l;
  int b = l + n - 1;
  if (a > 0) cout << (2 * l + n) * (n - 1) / 2 << endl;
  else if (b < 0) cout << (2 * l + n - 2) * (n - 1) / 2 << endl;
  else cout << (2 * l + n - 1) * n / 2 << endl;
}
