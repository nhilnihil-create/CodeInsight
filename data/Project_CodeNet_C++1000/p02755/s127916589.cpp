#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;
  int price = B * 10;
  int tax_8 = floor(price * 0.08);
  if (A == tax_8) cout << price << endl;
  else {
    int cnt = 0;
    while (true) {
      price++;
      tax_8 = floor(price * 0.08);
      if (A == tax_8) {
        cout << price << endl;
        break;
      }
      cnt++;
      if (cnt == 9) {
        cout << -1 << endl;
        break;
      }
    }
  }
}
