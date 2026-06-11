#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// from the last
int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i, n) cin >> a[i+1];
  vector<int> box(n+1);
  for (int i = n; i > 0; --i) {
    int cur = 0 ^ a[i];
    for (int j = i+i; j <= n; j += i) {
      cur ^= box[j];
    }
    box[i] = cur;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (box[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  rep(i, ans.size()) {
    printf("%d%c", ans[i], i+1==ans.size() ? '\n' : ' ');
  }
  return 0;
}