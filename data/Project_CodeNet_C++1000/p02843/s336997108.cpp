#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  if (x >= 10000) cout << 1 << endl;
  else {
    int a = x  / 100, b = x % 100;
    if (b <= a * 5) cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;
}