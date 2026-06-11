#include <bits/stdc++.h>
using namespace std;

//2*ra*rb < c - a - b
// 4*a*b < (c-a-b)^2

int main() {
  long double a, b, c;
  cin >> a >> b >> c;
  
  long double eps = 1e-14;
  
  if (4*a*b < pow(c-a-b, 2) && c-a-b > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}