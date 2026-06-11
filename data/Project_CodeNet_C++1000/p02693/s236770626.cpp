#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b;
  cin >> k >> a >> b;

  if ((b/k - a/k >= 1) || (a%k == 0)) {
    cout << "OK";
  }
  else {
    cout << "NG";
  }
  cout << endl;
}
