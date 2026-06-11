#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  
  cin >> a >> b >> c;
  
  bool ans = (c - a - b > 0 && 4 * a * b < (c - a - b) * (c - a - b));
  
  cout << (ans ? "Yes" : "No") << endl;
  
  return 0;
}