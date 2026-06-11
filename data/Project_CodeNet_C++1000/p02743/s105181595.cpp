#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t a, b, c; cin >> a >> b >> c;
  
  int64_t leftSide = 4 * a * b;
  
  int64_t tmp = c - a - b;
  
  int64_t rightSide = tmp * tmp;
  
  if (0 < tmp && leftSide < rightSide) cout << "Yes" << endl;
  
  else cout << "No" << endl;
  
}