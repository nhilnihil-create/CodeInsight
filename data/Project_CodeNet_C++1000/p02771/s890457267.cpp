#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && b == c) cout << "No" << endl;
  else if (a != b && b != c && c != a) cout << "No" << endl;
  else cout << "Yes" << endl;
}