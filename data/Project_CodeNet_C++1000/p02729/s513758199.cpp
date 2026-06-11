#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  int ans = 0;
  cin >> n >> m;
  rep(i, n) {
    ans += i;
  }
  rep(i, m) {
    ans += i;
  }
  cout << ans << endl;
  return 0;
}