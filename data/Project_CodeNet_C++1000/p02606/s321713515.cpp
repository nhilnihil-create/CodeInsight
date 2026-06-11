#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  int d;
  
  cin >> a;
  cin >> b;
  cin >> c;
  d = 0;
  
  for (int i = a; i <= b; i++) {
    int e = i;
    if (e%c == 0) {
      d++; 
    }
  }
  
  cout << d;
   
  return 0;
}