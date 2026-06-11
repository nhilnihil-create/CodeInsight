#include <bits/stdc++.h>
using namespace std;

int main() {
  int P, Q, R;
  int A, B, C;
  cin >> P >> Q >> R;
  
  A = P + Q;
  B = Q + R;
  C = R + P;
  
  cout << min(A, min(B, C)) << endl;
  
}