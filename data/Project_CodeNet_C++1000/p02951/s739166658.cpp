#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c > a - b) cout << c - a + b << endl;
  else cout << 0 << endl;
}