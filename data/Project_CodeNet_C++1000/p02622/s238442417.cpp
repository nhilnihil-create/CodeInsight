#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  string t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 0, N = s.size(); i < N; i++) {
    if (s[i] != t[i]) ans++;
  }
  cout << ans << endl;
}
