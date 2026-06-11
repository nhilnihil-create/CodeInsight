#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> a(n);
  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        ans += ((a.at(i) + a.at(j)) > a.at(k)) && a.at(i) != a.at(j) && a.at(j) != a.at(k) && a.at(k) != a.at(i);
      }
    }
  }
  cout << ans << endl;
}