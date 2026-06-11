#include <bits/stdc++.h>
using namespace std;

int main(){
  int X, Y, Z, n;
  cin >> X >> Y >> Z;
  
  n = X;
  X = Y;
  Y = n;
  
  n = X;
  X = Z;
  Z = n;
  
  cout << X << " " << Y << " " << Z << endl;
}