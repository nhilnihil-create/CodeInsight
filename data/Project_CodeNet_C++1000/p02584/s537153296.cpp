#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t X, K, D; cin >> X >> K >> D;
  
  X = abs(X);
  
  if (K < X / D) { cout << X - K * D << endl; return 0; }
  
  int64_t tmp = X / D;
  
  if ((tmp % 2) == (K % 2)) cout << X - D * tmp << endl;
  
  else cout << abs(X - D * (tmp + 1)) << endl;
  
}