#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 1e10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long mx1 = -inf;
  long long mx2 = -inf;
  long long mx3 = -inf;
  long long mx4 = -inf;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    mx1 = max(mx1, + x + y);
    mx2 = max(mx2, + x - y);
    mx3 = max(mx3, - x + y);
    mx4 = max(mx4, - x - y);
  }
  cout << max(mx1 + mx4, mx2 + mx3) << endl;
  return 0;
}
