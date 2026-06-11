#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c = 0;
  
  cin >> a;
  cin >> b;
  
  for (int i = 0; true; i++) {
    a = a - b;
    c++; // :):):)
    if (a <= 0) {
      cout << c;
      return 0;
    }
  }
    
  return 0;   
}