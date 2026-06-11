#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool jug = false;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (i * j == n) {
        jug = true;
      }
    }
  }
  if (jug) {
    cout << "Yes" << endl;
  } 
  else {
    cout << "No" << endl;
  }
}