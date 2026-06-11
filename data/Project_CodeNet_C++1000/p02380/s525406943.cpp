#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  double a, b, C; cin >> a >> b >> C;
  double S, L, h;
  h = b*sin(C*M_PI/180.0);
  S = a * h / 2;

  double a1, a2, c;
  a1 = sqrt(pow(b, 2)-pow(h, 2));
  if (C <= 90) {
    a2 = a - a1;
  } else {
    a2 = a + a1;
  }
  c = sqrt(pow(a2, 2)+pow(h, 2));
  L = a+b+c;
  
  cout << fixed << setprecision(6);
  cout << S << endl << L << endl << h << endl;
  return 0;
}