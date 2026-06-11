#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, p;
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    cin >> p;
    n -= p;
  }
  if (n<0) {
    cout << -1 << endl;
  }
  else {
    cout << n << endl;
  }
}