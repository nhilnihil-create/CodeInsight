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
  cin >> d;
  
  for (int i = 0; true;) {
    c = c - b;
    if (c <= 0) {
      cout << "Yes";
      return 0;
    }
    a = a - d;
    if (a <= 0) {
      cout << "No";
      return 0;
    }
  }
}