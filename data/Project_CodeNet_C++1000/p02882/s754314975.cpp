#include <bits/stdc++.h>
using namespace std;

const float pi = 3.14159265359;
int main() {

  float a, b, x;
  cin >> a >> b >> x;
  
  if (x > a * a * b /2) {
    cout << fixed << setprecision(12) << atan(2 * (a * a * b - x) / (a * a * a)) * 180 / pi << endl;
    
  } else {
    cout << fixed << setprecision(12) << atan(a * b * b / (2 * x)) * 180 / pi << endl;
  }
}