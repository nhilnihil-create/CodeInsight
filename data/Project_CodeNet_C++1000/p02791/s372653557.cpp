#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, min, ans;
  ans = 0;
  min = pow(10, 6);
  cin >> n;
  rep(i, n) {
    int p;
    cin >> p;
    if (p <= min) {
      ans++;
      min = p;
    }
  }
  cout << ans << endl;
  return 0;
}