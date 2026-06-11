#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while(true) {
    c -= b;
    if (c <= 0) {
      cout << "Yes" << endl;
      return 0;
    }
    for(int i=0; i<1; i++) {
      a -= d;
      if (a <= 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
}