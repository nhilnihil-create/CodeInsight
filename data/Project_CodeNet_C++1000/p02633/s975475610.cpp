#include <bits/stdc++.h>
using namespace std;

int main() {

  int x;
  cin >> x;
  int k = 1;

  if(360%x == 0) {
    cout << 360/x;
  } else{
    for (int i = 0; i < 10000; i++) {
    if (k*x%360 == 0) {
      cout << k;
      break;
    }
      k++;
  }
  }
}