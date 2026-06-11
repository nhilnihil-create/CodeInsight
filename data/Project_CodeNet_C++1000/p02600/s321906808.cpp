#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll m = 1e9 + 7;

int main() {
  int x;
  cin >> x;

  if (x <= 599) cout << 8 << endl;
  else if (x <= 799) cout << 7 << endl;
  else if (x <= 999) cout << 6 << endl;
  else if (x <= 1199) cout << 5 << endl;
  else if (x <= 1399) cout << 4 << endl;
  else if (x <= 1599) cout << 3 << endl;
  else if (x <= 1799) cout << 2 << endl;
  else if (x <= 1999) cout << 1 << endl;

}