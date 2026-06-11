#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  if (n == 1) {
    ans += 300000;
  }
  if (n == 2) {
    ans += 200000;
  }
  if (n == 3) {
    ans += 100000;
  }
  if (m == 1) {
    ans += 300000;
  }
  if (m == 2) {
    ans += 200000;
  }
  if (m == 3) {
    ans += 100000;
  }
  if ((n==1) && (m==1)) {
    ans += 400000;
  }
  cout << ans << endl;
}