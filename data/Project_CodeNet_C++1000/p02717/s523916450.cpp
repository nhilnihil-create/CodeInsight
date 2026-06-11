#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, a, b, c;
  cin >> A >> B >> C;
  
  a = A;
  b = B;
  c = C;
    A = b;
    B = a;
    A = c;
    C = b;
  cout << A << " " << B << " " << C << endl;
}