#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(int n, string s, int up) {
  if (n == 0) {
    cout << s << endl;
    return;
  }

  rep(i, up) solve(n - 1, s + char('a' + i), up);
  solve(n - 1, s + char('a' + up), up + 1);
}

int main() {
  ll n;
  cin >> n;
  string s;
  solve(n, s, 0);
  return 0;
}
