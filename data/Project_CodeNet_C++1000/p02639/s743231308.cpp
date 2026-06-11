#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  int C=1;
  for (int i=0; i<5; i++) {
    cin >> x;
    if (x==0) {
      cout << i+1 << endl;
      break;
    }
    C++;
  }
}