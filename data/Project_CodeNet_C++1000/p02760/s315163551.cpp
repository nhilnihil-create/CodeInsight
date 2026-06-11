#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<bool>> c(3, vector<bool>(3, false));
  for (auto&& v : a) {
    for (auto&& e : v) {
      cin >> e;
    }
  }
  int n;
  cin >> n;
  while (n--) {
    int b;
    cin >> b;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (a[i][j] == b) c[i][j] = true;
      }
    }
  }
  bool bingo = false;
  for (int i = 0; i < 3; i++) {
    bool ok = true;
    for (int j = 0; j < 3; j++) {
      if (!c[i][j]) ok = false;
    }
    if (ok) bingo = true;
  }
  for (int i = 0; i < 3; i++) {
    bool ok = true;
    for (int j = 0; j < 3; j++) {
      if (!c[j][i]) ok = false;
    }
    if (ok) bingo = true;
  }
  bool ok = true;
  for (int i = 0; i < 3; i++) {
    if (!c[i][i]) ok = false;
  }
  if (ok) bingo = true;
  ok = true;
  for (int i = 0; i < 3; i++) {
    int j = 2;
    if (i == 1)
      j = 1;
    else if (i == 2)
      j = 0;
    if (!c[i][j]) ok = false;
  }
  if (ok) bingo = true;
  cout << (bingo ? "Yes" : "No") << '\n';
  return 0;
}
