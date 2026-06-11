#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  int i = 1;
  while(true) {
    if(x * i % 360 == 0) {
      cout << i << endl;
      break;
    }
    i++;
  }
  return 0;
}