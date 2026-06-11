#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int x, ans = 0;
  cin >> x;
  ans += x / 500 * 1000;
  ans += (x % 500) / 5 * 5;
  cout << ans;
}