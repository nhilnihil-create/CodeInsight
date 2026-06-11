#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--, b--, c--, d--;
  string s;
  cin >> s;
  int left = a;
  int right = max(c, d);
  for (int i = left; i < right; i++) {
    if (s[i] == '#' && s[i + 1] == '#') {
      cout << "No" << '\n';
      return 0;
    }
  }
  if (c < d) {
    cout << "Yes" << '\n';
    return 0;
  }
  for (int i = b; i <= d; i++) {
    if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}
