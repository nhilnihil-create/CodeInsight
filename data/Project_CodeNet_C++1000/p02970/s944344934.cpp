#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d;
  cin >> n >> d;
  int ans;
  ans = (n + 2 * d) / (2 * d + 1);
  cout << ans << '\n';
  return 0;
}