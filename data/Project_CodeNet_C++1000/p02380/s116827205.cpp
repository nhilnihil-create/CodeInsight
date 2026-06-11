#include<iostream>
#include<iomanip>
#include<cmath>

int main(){
  double a, b, C, S, L, h, CRadian;
  using namespace std;

  cin >> a >> b >> C;
  CRadian = C * acos(-1) / 180;
  S = 0.5 * a * b * sin(CRadian);
  L = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(CRadian)) + a + b;
  h = 2 * S / a;

  cout << fixed << setprecision(5) << S << endl << L << endl << h << endl;
}