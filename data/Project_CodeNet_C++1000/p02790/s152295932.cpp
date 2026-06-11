#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, d;
  cin >> a >> b;
  
  if (a > b) {
    c = a;
    d = b;
  }
  else {
    c = b;
    d = a;
  }
  for (int i = 0; i < c; i++) {
    cout << d;
  }
  cout << endl;
}