#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> snk(n);
  for (int i = 0; i < k; i++) {
    int d; cin >> d;
    for (int i = 0; i < d; i++) {
      int a; cin >> a;
      snk.at(~-a)++;
    }
  }
  int ans = 0;
  for (auto e : snk) ans += e == 0;
  cout << ans << endl;
}