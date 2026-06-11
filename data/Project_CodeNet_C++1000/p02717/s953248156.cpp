#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  swap(X, Y);
  swap(X, Z);
  cout << X << "\n";
  cout << Y << "\n";
  cout << Z << "\n";
}