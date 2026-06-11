#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = ((b-1) + (a-2)) / (a-1);
  cout << ans << '\n';
  return 0;
}