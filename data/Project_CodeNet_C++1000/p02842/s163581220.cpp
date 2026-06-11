#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double n;
  cin >> n;
  
  double a = n / 1.08;
  double b = (n + 1.0) / 1.08;
  bool fin = false;
  
  for(int i = a; i <= b; i++) {
    if (a <= i && i < b) {
      cout << i << endl;
      fin = true;
      break;
    }
  }
  
  if (!fin) {
    cout << ":(" << endl;
  }
}

