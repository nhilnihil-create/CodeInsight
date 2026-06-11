#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  string T, S;
  cin >> S >> T;
  int ans = 10000;
  rep(i, S.size() - T.size() + 1) {
    int count = T.size();
    rep(j, T.size()) if (S.at(i + j) == T.at(j)) count--;
    ans = min(ans, count);
  }
  cout << ans;
}
