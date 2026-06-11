#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep(i, n) cin >> a.at(i);

  // どの整数が条件を満たすか先に調べる
  vector<int> f(1e6 + 1, 0);
  for (int x : a) {
    if (f.at(x) != 0) {
      f.at(x) = 2;
      continue;
    } else {
      for (int j = x; j < 1e6 + 1; j += x) {
        f.at(j)++;
      }
    }
  }

  int ans = 0;
  for (int x : a) {
    if (f.at(x) == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}