#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef double db;
int main () {
  const db PI = 3.14159265;
  db a, b, x;
  cin >> a >> b >> x;
  db V = a * a * b;
  if (x > V / 2) {
    x = V - x;
    x /= (a * a);
    x *= 2;
    cout << setprecision(13) << (atan(x / a) / PI) * 180  << endl;
  }
  else {
    x /= a;
    db k = x / b;
    k *= 2;
    cout << setprecision(13) << (atan(b / k) / PI) * 180 << endl;
  }
}

