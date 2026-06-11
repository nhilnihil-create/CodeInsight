#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  rep(i, N) cin >> W[i];
  int total = 0;
  rep(i, N) total += W[i];
  int cur = 0;
  int ans = 1e6;
  for (int i = 0; i < N; i++) {
    cur += W[i];
    ans = min(ans, abs(total - 2 * cur));
  }
  cout << ans << '\n';
  return 0;
}