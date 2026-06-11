#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, total = 0;
  rep(i, 3) {
    cin >> a;
    total += a;
  }
  cout << (total >= 22 ? "bust" : "win") << endl;
  return 0;
}
