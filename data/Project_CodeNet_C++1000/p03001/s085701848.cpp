#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, n, m;
  cin >> a >> b >> n >> m;
  cout << fixed << setprecision(11);
  cout << a*b/2 << " ";
  if (n == a/2 && m == b/2) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}