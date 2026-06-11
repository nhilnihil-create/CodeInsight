#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  rep(i, q) {
    int b;
    cin >> b;
    --b;
    a[b] += 1;
  }
  rep(i, n) {
    int ans = k - q + a[i];
    bool bl = ans > 0;
    if (bl) puts("Yes");
    else puts("No");
  }
  return 0;
}