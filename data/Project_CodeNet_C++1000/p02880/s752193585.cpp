#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a;
  b=0;
  for (int i=1; i<10; i++) {
    for (int j=1; j<10; j++) {
      if (a==i*j) {
        b=1;
      }
    }
  }
  if (b) cout << "Yes" << endl;
  else cout << "No" << endl;
}
