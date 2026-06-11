#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > ans;
  if (n%2) {
    for (int l = 1, r = n-1; l < r; l++, r--) {
      ans.push_back(make_pair(l,r));
    }
  } else {
    bool flag = false;
    for (int l = 1, r = n-1; l < r; l++, r--) {
      if (!flag && r-l <= n/2) {
        --r;
        flag = true;
      }
      ans.push_back(make_pair(l,r));
    }
  }
  for(int i = 0; i < m; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}