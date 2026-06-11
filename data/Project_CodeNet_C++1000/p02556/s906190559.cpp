#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  // a[i]=x[i]+y[i], b[i]=x[i]-y[i]
  // max(max(a[i]-a[j]),max(b[i]-b[j]))
  int a_min = INT_MAX, a_max = -INT_MAX;
  int b_min = INT_MAX, b_max = -INT_MAX;
  int x, y;
  rep(i, N) {
    cin >> x >> y;
    int a = x + y;
    int b = x - y;
    a_min = min(a, a_min);
    a_max = max(a, a_max);
    b_min = min(b, b_min);
    b_max = max(b, b_max);
  }
  cout << max(a_max - a_min, b_max - b_min) << endl;
  return 0;
}