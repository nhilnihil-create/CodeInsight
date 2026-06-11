#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int cf = c / b;
  if (c % b) {
    cf++;
  }

  int cl = a / d;
  if (a % d) {
    cl++;
  }

  if (cf > cl) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}