#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> a(n);
  for (auto& e : a) {
    cin >> e;
    if (e == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  long long ans = 1;
  long long thres = 1e18;
  for (auto e : a) {
    if (thres / e < ans) {
      cout << -1 << endl;
      return 0;
    }
    ans *= e;
  }
  cout << ans << endl;
}