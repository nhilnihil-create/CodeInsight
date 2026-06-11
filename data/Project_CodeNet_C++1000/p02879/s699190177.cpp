#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  
  cin >> a;
  cin >> b;
  
  if (a > 9 || b > 9) {
    cout << "-1";
    return 0;
  }
  
  cout << a * b;
    
  return 0;   
}