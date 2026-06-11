#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int64_t X, p = 100, ans = 0;
  cin >> X;
  while (p < X) {
    p += p / 100;
    ans++;
  }
  cout << ans << endl;
}