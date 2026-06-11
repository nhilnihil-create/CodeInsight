#include <bits/stdc++.h>
using namespace std;
double pai = 3.14159265;

int main(){
  cout << fixed << setprecision(8);
  double a,b,C;
  cin >> a >> b >> C;
  C = C / 180 * pai;
  double S,L,h;
  S = a * b * sin(C) / 2;
  double c = sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(C));
  L = a + b + c;
  h = S * 2 / a;
  cout << S << endl << L << endl << h;
  return 0;
}

