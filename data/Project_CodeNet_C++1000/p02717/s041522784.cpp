#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int A = 0;
  A = X;
  X = Y;
  Y = A;
  
  A = X;
  X = Z;
  Z = A;
  
  cout << X << endl;
  cout << Y << endl;
  cout << Z << endl;
}
