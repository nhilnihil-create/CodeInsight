#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<int> cnt(n, 0);
  for (int i = 1; i < n; i++) {
    if (h[i - 1] >= h[i]) {
      cnt[i] = cnt[i - 1] + 1;
    }
  }
  sort(cnt.begin(), cnt.end());
  cout << cnt[n - 1] << endl;
  return 0;
}