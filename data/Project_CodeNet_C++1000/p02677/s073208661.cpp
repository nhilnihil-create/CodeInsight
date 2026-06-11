#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long double A, B, H, M;
  cin >> A >> B >> H >> M;
  long double PI = 3.14159265358979;
  long double rad = 2.0*PI*((H+M/60.0)/12.0 - M/60.0);
  cout << fixed << setprecision(10);
  cout << pow(A*A + B*B - 2*A*B*cosl(rad), 0.5) << endl;
}