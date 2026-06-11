#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int a,b,c;
  a = X;
  b = Y;
  c = Z;
  X = c;
  Y = a;
  Z = b;
  cout << X << " " << Y << " " << Z << " " << endl;
}
