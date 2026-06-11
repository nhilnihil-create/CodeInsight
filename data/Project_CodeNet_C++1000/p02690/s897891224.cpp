#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  
  for (int i = 120; i > -121; i--) {
    for (int j = -120; j < 121; j++) {
      int C = i-j;
      int D = i*i*i*i + i*i*i*j + i*i*j*j + i*j*j*j + j*j*j*j;
      if (C * D == X){
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  }
}
  
 