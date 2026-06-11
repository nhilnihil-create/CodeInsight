#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (a > 0 && c > 0) {
    c -= b;
    a -= d;
  }
  string ans = c > 0 ? "No" : "Yes";
  cout << ans << endl;
}
