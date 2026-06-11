#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  if ((b - 1) % (a - 1) == 0) {
    cout << (b - 1) / (a - 1) << endl;
  } else {
    cout << (b - 1) / (a - 1) + 1 << endl;
  }
  return 0;
}
