#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  rep(i, n) {
    int a;
    cin >> a;
    vp[i] = make_pair(a, i);
  }
  sort(vp.begin(), vp.end());
  rep(i, n) {
    if (vp[n - 1].second == i) {
      cout << vp[n - 2].first << endl;
    }
    else {
      cout << vp[n - 1].first << endl;
    }
  }
  return 0;
}
