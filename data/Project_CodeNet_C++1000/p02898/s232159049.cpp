#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int ans = 0;
  rep(i, n) {
    if (h[i] < k) continue;
    ans++;
  }
  cout << ans << '\n';
  return 0;
}