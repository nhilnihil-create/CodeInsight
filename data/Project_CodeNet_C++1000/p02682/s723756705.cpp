#include <bits/stdc++.h>
using namespace std;

int main() {
  long a, b, c, k;
  cin >> a >> b >> c >> k;
  
  if (k <= a) cout << k;
  else if (k > a && k <= a + b) cout << a;
  else cout << a - (k - a - b);
  
  return 0;
}