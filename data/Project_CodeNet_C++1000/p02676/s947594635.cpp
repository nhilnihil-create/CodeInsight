#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  string b;
  string c = "";
  
  cin >> a;
  cin >> b;
  
  if (a >= b.size()) {
    cout << b;
    return 0;
  }
  
  for (int i = 0; i < a; i++) {
    c = c + b[i];
  }
  
  cout << c;
  cout << "...";
    
  return 0;   
}