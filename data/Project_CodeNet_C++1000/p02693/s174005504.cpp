#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,a,b;
  cin >> k;
  cin >> a >> b;

  for (int i = 1; i < 1001; i++) {
    if (i % k == 0 && a <= i && i <= b) {
        cout << "OK" << endl;
        return 0;
    }
  }

  cout << "NG" << endl;

}
