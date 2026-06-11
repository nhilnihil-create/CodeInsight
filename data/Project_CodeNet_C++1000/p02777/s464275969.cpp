#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int x, y;
  cin >> x >> y;
  string color;
  cin >> color;
  if (color == a) {
    cout << x - 1 << " " << y << '\n';
  } else {
    cout << x << " " << y - 1 << '\n';
  }
  return 0;
}