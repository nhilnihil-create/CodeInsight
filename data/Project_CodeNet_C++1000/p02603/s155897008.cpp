#include<bits/stdc++.h>
using namespace std;

int main() {
  long long D, p = 300, q = 0, mon = 1000;
  cin >> D;
  bool b = true;
  for (int i = 0; i < D; i++) {
    int x;
    cin >> x;
    if (b) {
      if (p > x) p = x;
      if (p < x) {
        b = !b;
        q = x;
      }
    }
    else {
      if (q < x) q = x;
      if (q > x) {
        b = !b;
        mon = mon/p*q + (mon%p);
        p = x;
        q = 0;
      }
    }
  }
  if (p < q) mon = mon/p*q + (mon%p);
  cout << mon << endl;
}