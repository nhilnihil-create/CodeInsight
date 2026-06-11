#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<string> gen;
void solve(string s) {
  if (s.length() > n || s.length() > 1 && s.front() == '0')
    return;
  if (s.length() == n) {
    gen.push_back(s);
  }
  for (char i = '0'; i <= '9'; i++)
    solve(s + i);

}
int main() {
  cin >> n >> m;
  solve("");
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (auto x : gen) {
    bool ok = true;
    //cout << x << '\n';
    for (auto y : a) {
      if (x[y.first - 1] != (char) (y.second + '0')) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << x << '\n';
      return 0;
    }
  }
  cout << -1;
  return 0;
}
