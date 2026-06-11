#include <bits/stdc++.h>
using namespace std;

int main() {
  double A, B, C, D;
  cin >> A >> B >> C >> D;
  int taka, ao;
  double x, y;
  x=A/D;
//  cout << x << endl;
  taka = ceil (x);
//  cout << taka << endl;
  y=C/B;
//  cout << y << endl;
  ao = ceil (y);
//  cout << ao << endl;
  if (taka >= ao)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
