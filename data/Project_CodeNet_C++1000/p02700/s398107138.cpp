#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int X = C / B, Y = A / D;
  if (C % B != 0) {
    X++;
  }
  if (A % D != 0) {
    Y++;
  }  
  if (X <= Y) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
     