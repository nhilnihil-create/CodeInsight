#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int main() {
  int A,B,H,M;
  cin >> A >> B >> H >> M; 
  cout << fixed << setprecision(16);
  
  long double pi = 3.1415926535897932384626433832795;
  
  //radianへの変換
  long double h = H/12.0+(M/60.0)/12.0;
  long double m = M/60.0;
  long double x = 2.0*pi*(h-m);

  //余弦定理で出す
  long double d = (double) (A*A + B*B) -2.0*A*B*cos(x);
  cout << sqrt(d) << endl;
  
}