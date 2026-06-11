#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  rep(i, 1010) {
    int aa = i * 8 / 100;
    int bb = i * 10 / 100;
    if (a == aa && b == bb) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
