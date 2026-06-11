#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int p, q, r;
  cin >> p >> q >> r;
  
  if (p >= q && p >= r) {
    cout << q + r << endl;
  } else if (q >= p && q >= r) {
    cout << p + r << endl;
  } else {
    cout << p + q << endl;
  }
  
}
