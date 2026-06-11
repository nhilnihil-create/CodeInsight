#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a/10>0 || b/10>0) {
    cout << -1 << endl;
  }
  else {
    cout << a*b << endl;
  }
}