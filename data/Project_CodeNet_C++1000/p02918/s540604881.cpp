#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int h = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L' && i > 0 && s[i - 1] == 'L') h++;
    if (s[i] == 'R' && i < n - 1 && s[i + 1] == 'R') h++;
  }
  h += k * 2;
  int ans = min(h, n - 1);
  cout << ans << endl;
}
