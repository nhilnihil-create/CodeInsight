#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int a, b, C;
  double S, L, h, rad;

  cin >> a >> b >> C;
  rad = C * M_PI /180;
  S = (a * b * sin(rad)) / 2;
  L = a + b + sqrt(pow(a,2.0) + pow(b,2.0) - 2 * a * b * cos(rad));
  h = b * sin(rad);
  cout << fixed << S << endl;
  cout << L << endl;
  cout << h << endl;
  return 0;
}