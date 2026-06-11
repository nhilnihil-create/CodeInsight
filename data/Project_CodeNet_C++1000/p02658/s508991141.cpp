#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int64_t ans = 1;
  vector<int64_t> vec(n);
  rep(i, n) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  if (vec.at(0) == 0) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, n) {
    if (vec.at(i) > 1000000000000000000 /ans) {
      cout << -1 << endl;
      return 0;
    }
    ans *= vec.at(i);
  }
  cout << ans << endl;
}