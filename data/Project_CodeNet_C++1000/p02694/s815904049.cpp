#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll X;
  cin >> X;
  ll now = 100;
  for (int i = 1;; i++) {
    now += now / 100;
    if (now >= X) {
      cout << i << endl;
      return 0;
    }
  }
}