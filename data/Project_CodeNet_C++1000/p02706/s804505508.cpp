#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, a;
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    cin >> a;
    n -= a;
  }
  if (n>=0) cout << n << endl;
  else cout << -1 << endl;
  return 0;
}