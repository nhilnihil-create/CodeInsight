#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (auto&& c : s) {
    c = 'A' + (c + n - 'A') % 26;
    cout << c;
  }
  return 0;
}
