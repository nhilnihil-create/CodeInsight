#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b;
  cin >> k >> a >> b;

  bool fin = false;
  for (int i = 0; i <= b-a; i++) {
    if ((a+i)%k == 0) {
      cout << "OK" << endl;
      fin = true;
      break;
    }
  }
  if (!fin) {
    cout << "NG" << endl;
  }
}