#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int res = 0;
  long long d;
  cin >> d;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    res += (x * x + y * y <= d * d);
  }
  cout << res << endl;
}
