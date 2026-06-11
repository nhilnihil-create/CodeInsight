#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  bool ok = true;
  while (n--) {
    int a;
    cin >> a;
    if (a % 2) continue;
    if (a % 3 && a % 5) {
      ok = false;
    }
  }
  cout << (ok ? "APPROVED" : "DENIED") << '\n';
  return 0;
}
