#include <bits/stdc++.h>
using namespace std;

int main() {
  long n, m;
  cin >> n >> m;
  long a[m];
  for (long i = 0; i < m; i++) {
    cin >> a[i];
    n -= a[i];
    if (n < 0) {
      cout << -1;
      return 0;
    }
  }
  
  cout << n;
  
  return 0;
}