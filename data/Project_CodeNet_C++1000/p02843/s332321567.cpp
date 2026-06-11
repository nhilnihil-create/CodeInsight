#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int X; cin >> X;
  
  int quotient = X / 100; int remainder = X % 100;
  
  if (X < 100) cout << "0" << endl;
  
  else if (1999 < X) cout << "1" << endl;
  
  else {
    
    if (remainder <= quotient * 5) cout << "1" << endl;
    
    else cout << "0" << endl;
       
  }
  
}