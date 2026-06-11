#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;
  vector<int> cnt(n);
  rep(i, n - 1) {
    for(int j = i + 1; j < n; j++) {
      int a;
      a = min(j - i, abs(x - i) + 1 + abs(j - y));
      cnt[a]++;
    }
  }
  rep(i, n - 1) cout << cnt[i + 1] << endl;
}
