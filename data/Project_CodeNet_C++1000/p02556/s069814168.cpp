#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) {
    int x, y;
    cin >> x >> y;
    a[i] = x-y;
    b[i] = x+y;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = max(a.back()-a.front(), b.back()-b.front());
  cout << ans << endl;
  return 0;
}
