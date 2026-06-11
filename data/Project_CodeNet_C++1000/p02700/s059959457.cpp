#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int takahashiLife = a / d;
  int aokiLife = c / b;
  if (a % d > 0) {
    takahashiLife = takahashiLife + 1;
  }
  if (c % b > 0) {
    aokiLife = aokiLife + 1;
  }
  if (takahashiLife >= aokiLife) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
