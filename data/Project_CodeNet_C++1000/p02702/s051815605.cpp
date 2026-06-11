#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  V<int> curr(2020), prev(2020);

  ll ans = 0;
  rep(i, n) {
    fill(curr.begin(), curr.end(), 0);
    int p = s[i] - '0';
    if (p != 0) curr[p] += 1;

    rep(j, 2020) {
      if (prev[j] > 0) {
        int p = (j * 10 + s[i] - '0') % 2019;
        curr[p] += prev[j];
      }
    }
    ans += curr[0];
    prev = curr;
  }
  cout << ans << endl;
}
