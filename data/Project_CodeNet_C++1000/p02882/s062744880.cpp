#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  float a,b;
  int x;
  cin >> a >> b >> x;
  cout << fixed << setprecision(8);
  if (x >= a*a*b/2) {
    float k = (2*a*a*b-2*x)/(a*a*a);
    cout << (float)atan(k)*360/2/pi << endl;
  }
  else {
    float k = a*b*b/(2*x);
    cout << (float)atan(k)*360/2/pi << endl;
  }
}