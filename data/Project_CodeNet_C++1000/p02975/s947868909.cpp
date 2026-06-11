#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  if (cnt.size() > 3) {
    cout << "No" << '\n';
    return 0;
  }
  for (auto a : cnt) {
    for (auto b : cnt) {
      int x = a.first, y = b.first, z = x ^ y;
      if (!cnt.count(z)) {
        continue;
      }
      map<int, int> cur;
      vector<int> c(n);
      c[0] = x, c[1] = y, c[2] = z;
      ++cur[x], ++cur[y], ++cur[z];
      bool bad = false;
      for (int i = 3; i < n; i++) {
        if (i % 3 == 0) {
          c[i] = x;
          ++cur[x];
          if (cur[x] > cnt[x]) {
            bad = true;
            break;
          }
        } else if (i % 3 == 1) {
          c[i] = y;
          ++cur[y];
          if (cur[y] > cnt[y]) {
            bad = true;
            break;
          }
        } else {
          c[i] = z;
          ++cur[z];
          if (cur[z] > cnt[z]) {
            bad = true;
            break;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if ((c[(i - 1 + n) % n] ^ c[(i + 1) % n]) != c[i]) {
          bad = true;
          break;
        }
      }
      if (!bad) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }
  cout << "No" << '\n';
  return 0;
}
